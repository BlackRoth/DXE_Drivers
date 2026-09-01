The HelloDxe is a simple Hello world Driver of sorts. It prints a message right before TianoCore attempts to boot the first boot option, not before the firmware starts. It is a pre-OS Driver.<br>

The pathway of the HelloDxe.inf should be pasted inside the [COMPONENTS] partition in OvmfPkg/OvmfPkgX64.dsc <br>

The pathway of the HelloDxe.inf should be pasted inside the [FV.DXEFV] partition in OvmfPkg/OvmfPkgX64.fdf <br>

The below was done using the terminal:<br>
```cd edk2``` <br>
```. edksetup.sh``` <br>

To create a debug file to check whether the driver has been executed/loaded, use the command below: <br>
```build -a X64 -t GCC -b DEBUG -p OvmfPkg/OvmfPkgX64.dsc -D DEBUG_ON_SERIAL_PORT```<br>

Now launch QEMU by using this command below.<br>
```qemu-system-x86_64 -bios Build/OvmfX64/DEBUG_GCC/FV/OVMF.fd -net none -serial file:serial.log```<br>

The driver registers a callback on the Ready-To-Boot event instead of printing directly at load time. This means the message appears only after the console is fully connected and the standard boot-menu timeout has passed -- right before the first boot attempt.<br>

An earlier version tried printing directly using a Depex on the console protocol, but that failed silently: the protocol existing isn't the same as the console being connected to a real device. Switching to Ready-To-Boot fixed this by guaranteeing the console is live.


