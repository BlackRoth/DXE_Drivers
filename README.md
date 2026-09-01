<ins>**DXE Driver Development- UEFI Firmware Portfolio**</ins>

This repository tracks my progress building custom DXE drivers for
UEFI firmware using EDK2 on Linux (Ubuntu based). Focused on driver
dispatch behavior, event-driven execution, and boot-phase timing
inside the pre-OS firmware environment.

<ins>**Core Engineering Focus**</ins>

**Driver Dispatch & Dependency Resolution:** Understanding how the
DXE Core loads drivers based on dependency expressions (Depex), and
how protocol availability differs from protocol readiness.

**Event-Driven Execution:** Registering callbacks against UEFI event
groups to defer driver behavior until the
correct boot-phase milestone, rather than relying on Depex alone.

**Boot Phase Awareness:** Distinguishing DXE dispatch from BDS (Boot
Device Selection) — tracing how console output, protocol installation,
and device connection are staged across separate phases of boot.

**Bare-Metal Development:** Writing freestanding C drivers with no
OS, no libc, and manual control over entry point, execution timing,
and console/debug output channels.

<ins>**Development Environment & Toolchain**</ins>

- **OS:** Linux — Zorin OS / Ubuntu Core Base
- **Framework:** TianoCore EDK2 (EFI Development Kit II)
- **Target Architecture:** X64 (64-bit Long Mode)
- **Compiler:** GCC (GNU Compiler Collection)
- **Simulation:** QEMU Virtualization with Open Virtual Machine Firmware (OVMF)
- **Debug Output:** Serial log via `DEBUG_ON_SERIAL_PORT` build flag
