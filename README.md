# MathLibrary DLL

[A DLL](https://learn.microsoft.com/en-us/troubleshoot/windows-client/deployment/dynamic-link-library) is a library that contains code and data that can be used by more than one program at the same time. For example, in Windows operating systems, the Comdlg32 DLL performs common dialog box related functions. Each program can use the functionality that is contained in this DLL to implement an Open dialog box. It helps promote code reuse and efficient memory usage.

In order to learn a bit more about windows OS and what actually happens "behind the scenes",
i've tried to implement my own DLL and saw [Microsoft's walkthrough](https://learn.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-dynamic-link-library-cpp?view=msvc-170).

that's my own implement, adding a bit code of my own to the original code in the tutorial
