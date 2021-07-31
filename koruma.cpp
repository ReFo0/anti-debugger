#include "koruma.h"

std::uint32_t process(const std::string& name)
{
    const auto snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap == INVALID_HANDLE_VALUE) {
        return 0;
    }

    PROCESSENTRY32 proc_entry{};
    proc_entry.dwSize = sizeof proc_entry;

    auto found_process = false;
    if (!!Process32First(snap, &proc_entry)) {
        do {
            if (name == proc_entry.szExeFile) {
                found_process = true;
                break;
            }
        } while (!!Process32Next(snap, &proc_entry));
    }

    CloseHandle(snap);
    return found_process
        ? proc_entry.th32ProcessID
        : 0;
}


void titlekoruma() {
    for (;;) {
        HWND slm1 = FindWindowW(_xor_(L"Qt5QWindowIcon").c_str(), 0);  // Class ID denetleyici 
        if (slm1)
        {
            MessageBoxA(NULL, _xor_("Debugger Detected").c_str(), _xor_("Security").c_str(), MB_ICONERROR);
            Sleep(1);
            exit(1);
        }
        HWND slm2 = FindWindow(NULL, (_xor_("OllyDbg").c_str())); // Title Denetleyici
        if (slm2)
        {
            MessageBoxA(NULL, _xor_("Debugger Detected").c_str(), _xor_("Security").c_str(), MB_ICONERROR);
            Sleep(1);
            junk();
            exit(1);
        }
        HWND slm3 = FindWindowW(_xor_(L"XTPMainFrame").c_str(), 0); // Class ID denetleyici 
        if (slm3)
        {
            MessageBoxA(NULL, _xor_("Debugger Detected").c_str(), _xor_("Security").c_str(), MB_ICONERROR);
            Sleep(1);
            junk();
            exit(1);
        }
        HWND slm4 = FindWindow(NULL, (_xor_("HTTP Debugger").c_str())); // Title Denetleyici
        if (slm4)
        {
            MessageBoxA(NULL, _xor_("Debugger Detected").c_str(), _xor_("Security").c_str(), MB_ICONERROR);
            Sleep(1);
            exit(1);
        }
        HWND slm5 = FindWindowW(_xor_(L"XTPMainFrame").c_str(), 0); // Class ID denetleyici 
        if (slm5)
        {
            MessageBoxA(NULL, _xor_("Debugger Detected").c_str(), _xor_("Security").c_str(), MB_ICONERROR);
            Sleep(1);
            exit(1);
        }
    }
    Sleep(1000);
}

void Debugkoruma() {
    junk();
    std::cout << _xor_("\n  ");
    __try {
        DebugBreak();
    }
    __except (GetExceptionCode() == EXCEPTION_BREAKPOINT ?
        EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH) {
        std::cout << _xor_("\n  ");
        junk();
    }
}

void selamdebugger() {
    junk();
    SetLastError(0);
    junk();
    OutputDebugStringA("selam, debugger");
    if (GetLastError() != 0)
    {
        junk();
        MessageBoxA(NULL, _xor_("Debugger Detected").c_str(), _xor_("Security").c_str(), MB_OK);
        Sleep(1);
        exit(1);
        junk();
    }
}

void koruma0() {

    {
        if (IsDebuggerPresent())
        {
            MessageBoxA(NULL, _xor_("Debugger Detected").c_str(), _xor_("Security").c_str(), MB_OK);
            Sleep(1);
            exit(1);
        }
    }
}


void exedenetleme() { // basit yöntem // simple method
    DWORD exe1 = process("ollydbg.exe");
    if (exe1) {
        exit(1);
    }
    DWORD exe2 = process(_xor_("ida64.exe").c_str());
    if (exe2) {
        exit(1);
    }
    DWORD exe3 = process(_xor_("HTTPDebuggerUI.exe").c_str());
    if (exe3) {
        exit(1);
    }
    DWORD exe4 = process(_xor_("x64dbg.exe").c_str());
    if (exe4) {
        exit(1);
    }
    DWORD exe5 = process(_xor_("x32dbg.exe").c_str());
    if (exe5) {
        exit(1);
    }
    DWORD exe6 = process(_xor_("Scylla_x64.exe").c_str());
    if (exe6) {
        exit(1);
    }
    DWORD exe7 = process(_xor_("Scylla_x86.exe").c_str());
    if (exe7) {
        exit(1);
    }
    DWORD exe8 = process(_xor_("HxD.exe").c_str());
    if (exe8) {
        exit(1);
    }
    DWORD exe9 = process(_xor_("patch.exe").c_str());
    if (exe9) {
        exit(1);
    }
    DWORD exe10 = process(_xor_("Fiddler Everywhere.exe").c_str());
    if (exe10) {
        exit(1);
    }
    DWORD exe11 = process(_xor_("HTTPDebuggerSvc.exe").c_str());
    if (exe11) {
        exit(1);
    }
    DWORD exe12 = process(_xor_("dumpcap.exe").c_str());
    if (exe12) {
        exit(1);
    }
    DWORD exe13 = process(_xor_("Wireshark.exe").c_str());
    if (exe13) {
        exit(1);
    }
    DWORD exe14 = process(_xor_("ProcessHacker.exe").c_str());
    if (exe14) {
        exit(1);
    }
    DWORD exe15 = process(_xor_("ksdumper.exe").c_str());
    if (exe15) {
        exit(1);
    }
    cout << _xor_(":) Temiz").c_str(); /* eðer yukarýda verilen programlardan birini açmadýysa verilen
      mesajdýr mesajý isterseniz MessageBoxA Olarak yada ekrana benim yaptýðým gibi yazdýrabilirsiniz*/
}

void genelkoruma() {
    junk();
    Debugkoruma();
    junk();
    selamdebugger();
    junk();
    koruma0();
    junk();
    exedenetleme();
    junk();
    titlekoruma();
    junk();
}

