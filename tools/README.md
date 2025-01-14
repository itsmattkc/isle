# LEGO Island Decompilation Tools

Accuracy to the game's original code is the main goal of this project. To facilitate the decompilation effort and maintain overall quality, we have devised a set of annotations, to be embedded in the source code, which allow us to automatically verify the accuracy of re-compiled functions' assembly, virtual tables, variable offsets and more.

In order for contributions to be accepted, the annotations must be used in accordance to the rules outlined here. Proper use is enforced by [GitHub Actions](/.github/workflows) which run the Python tools found in this folder. It is recommended to integrate these tools into your local development workflow as well.

# Overview

We are continually working on extending the capabilities of our "decompilation language" and the toolset around it. Some of the following annotations have not made it into formal verification and thus are not technically enforced on the source code level yet (marked as **WIP**). Nevertheless, it is recommended to use them since it is highly likely they will eventually be fully integrated.

## Functions

All non-inlined functions in the code base with the exception of [3rd party code](/3rdparty) must be annotated with one of the following markers, which include the module name and address of the function as found in the original binaries. This information is then used to compare the recompiled assembly with the original assembly, resulting in an accuracy score. Functions in a given compilation unit must be ordered by their address in ascending order.

The annotations can be attached to the function implementation, which is the most common case, or use the "comment" syntax (see examples below) for functions that cannot be referred to directly (such as templated, synthetic or non-inlined inline functions). They should appear exclusively in `.cpp` files.

### `FUNCTION`

Functions with a reasonably complete implementation which are not templated or synthetic (see below) should be annotated with `FUNCTION`.

```
// FUNCTION: LEGO1 0x100b12c0
MxCore* MxObjectFactory::Create(const char* p_name)
{
  // implementation
}

// FUNCTION: LEGO1 0x100140d0
// MxCore::IsA
```

### `STUB`

Functions with no or a very incomplete implementation should be annotated with `STUB`. These will not be compared to the original assembly.

```
// STUB: LEGO1 0x10011d50
LegoCameraController::LegoCameraController()
{
  // TODO
}
```

### `TEMPLATE`

Templated functions should be annotated with `TEMPLATE`. Since the goal is to eventually have a full accounting of all the functions present in the binaries, please make an effort to find and annotate every function of a templated class.

```
// TEMPLATE: LEGO1 0x100c0ee0
// list<MxNextActionDataStart *,allocator<MxNextActionDataStart *> >::_Buynode

// TEMPLATE: LEGO1 0x100c0fc0
// MxStreamListMxDSSubscriber::~MxStreamListMxDSSubscriber

// TEMPLATE: LEGO1 0x100c1010
// MxStreamListMxDSAction::~MxStreamListMxDSAction
```

### `SYNTHETIC`

Synthetic functions should be annotated with `SYNTHETIC`. A synthetic function is generated by the compiler; for the time being, the only case is the "scalar deleting destructor" found in virtual tables. Note: `SYNTHETIC` takes precedence over `TEMPLATE`.

```
// SYNTHETIC: LEGO1 0x10003210
// Helicopter::`scalar deleting destructor'

// SYNTHETIC: LEGO1 0x100c4f50
// MxCollection<MxRegionLeftRight *>::`scalar deleting destructor'

// SYNTHETIC: LEGO1 0x100c4fc0
// MxList<MxRegionLeftRight *>::`scalar deleting destructor'
```

## Virtual tables (**WIP**)

Classes with a virtual table should be annotated using the `VTABLE` marker, which includes the module name and address of the virtual table. Additionally, virtual function declarations should be annotated with a comment indicating their relative offset. Please use the following example as a reference.

```
// VTABLE: LEGO1 0x100dc900
class MxEventManager : public MxMediaManager {
public:
	MxEventManager();
	virtual ~MxEventManager() override;

	virtual void Destroy() override;                                     // vtable+0x18
	virtual MxResult Create(MxU32 p_frequencyMS, MxBool p_createThread); // vtable+0x28
```

## Class size (**WIP**)

Classes should be annotated using the `SIZE` marker to indicate their size. If you are unsure about the class size in the original binary, please use the currently available information (known member variables) and detail the circumstances in an extra comment if necessary.

```
// SIZE 0x1c
class MxCriticalSection {
public:
	__declspec(dllexport) MxCriticalSection();
	__declspec(dllexport) ~MxCriticalSection();
	__declspec(dllexport) static void SetDoMutex();
```

## Member variables (**WIP**)

Member variables should be annotated with their relative offsets.

```
class MxDSObject : public MxCore {
private:
	MxU32 m_sizeOnDisk; // 0x8
	MxU16 m_type;       // 0xc
	char* m_sourceName; // 0x10
	undefined4 m_unk14; // 0x14
```

## Global variables (**WIP**)

Global variables should be annotated using the `GLOBAL` marker, which includes the module name and address of the variable.

```
// GLOBAL: LEGO1 0x100f456c
MxAtomId* g_jukeboxScript = NULL;

// GLOBAL: LEGO1 0x100f4570
MxAtomId* g_pz5Script = NULL;

// GLOBAL: LEGO1 0x100f4574
MxAtomId* g_introScript = NULL;
```

# Tooling

Use `pip` to install the required packages to be able to use the Python tools found in this folder:

```
pip install -r tools/requirements.txt
```

* [`reccmp`](/tools/reccmp): Compares the original EXE or DLL with a recompiled EXE or DLL, provided a PDB file
* [`verexp`](/tools/checkorder): Verifies exports by comparing the exports of the original DLL and the recompiled DLL
* [`checkorder`](/tools/checkorder): Checks function declarations, ensuring they appear in ascending order within a unit
* [`isledecomp`](/tools/isledecomp): A library that implements a parser to identify the "decompilation" annotations (see above)

## Testing

`isledecomp` has a small suite of tests. Install `pylint` and run it, passing in the directory:

```
pip install pytest
pytest tools/isledecomp/tests/
```

## Development

In order to keep the code clean and consistent, we use `pylint` and `black`:

`pip install black pylint`

### Run pylint (ignores build and virtualenv)

`pylint tools/ --ignore=build,bin,lib`

### Check code formatting without rewriting files

`black --check tools/`

### Apply code formatting

`black tools/`
