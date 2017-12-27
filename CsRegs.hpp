// -*- c++ -*-

#pragma once

#include <cstdint>
#include <vector>
#include <map>
#include <string>

namespace WdRiscv
{

  /// Privilige mode.
  enum PrivilegeMode { USER_MODE = 0, RESERVED_MODE = 2, SUPERVISOR_MODE = 1,
		       MACHINE_MODE = 3 };

  /// Costrol and status register number.
  enum CsrNumber
    {
      // Machine mode registers.

      // Machine info.
      MVENDORID_CSR = 0xF11,
      MARCHID_CSR = 0xF12,
      MIMPID_CSR = 0xF13,
      MHARTID_CSR = 0xF14,

      // Machine trap setup.
      MSTATUS_CSR = 0x300,
      MISA_CSR = 0x301,
      MEDELEG_CSR = 0x302,
      MIDELEG_CSR = 0x303,
      MIE_CSR = 0x304,
      MTVEC_CSR = 0x305,
      MCOUNTEREN_CSR = 0x306,

      // Machine trap handling
      MSCRATCH_CSR = 0x340,
      MEPC_CSR = 0x341,
      MCAUSE_CSR = 0x342,
      MTVAL_CSR = 0x343,
      MIP_CSR = 0x344,

      // Machine protection and translation.
      PMPCFG0_CSR = 0x3a0,
      PMPCFG1_CSR = 0x3a1,
      PMPCFG2_CSR = 0x3a2,
      PMPCFG3_CSR = 0x3a3,
      PMADDR0_CSR = 0x3b0,
      PMADDR1_CSR = 0x3b1,
      PMADDR2_CSR = 0x3b2,
      PMADDR3_CSR = 0x3b3,
      PMADDR4_CSR = 0x3b4,
      PMADDR5_CSR = 0x3b5,
      PMADDR6_CSR = 0x3b6,
      PMADDR7_CSR = 0x3b7,
      PMADDR8_CSR = 0x3b8,
      PMADDR9_CSR = 0x3b9,
      PMADDR10_CSR = 0x3ba,
      PMADDR11_CSR = 0x3bb,
      PMADDR12_CSR = 0x3bc,
      PMADDR13_CSR = 0x3bd,
      PMADDR14_CSR = 0x3be,
      PMADDR15_CSR = 0x3bf,

      // Machine Counter/Timers
      MCYCLE_CSR = 0xb00,
      MINSTRET_CSR = 0xb02,
      MHPMCOUNTER3_CSR = 0xb03,
      MHPMCOUNTER4_CSR = 0xb04,
      MHPMCOUNTER5_CSR = 0xb05,
      MHPMCOUNTER6_CSR = 0xb06,
      MHPMCOUNTER7_CSR = 0xb07,
      MHPMCOUNTER8_CSR = 0xb08,
      MHPMCOUNTER9_CSR = 0xb09,
      MHPMCOUNTER10_CSR = 0xb0a,
      MHPMCOUNTER11_CSR = 0xb0b,
      MHPMCOUNTER12_CSR = 0xb0c,
      MHPMCOUNTER13_CSR = 0xb0d,
      MHPMCOUNTER14_CSR = 0xb0e,
      MHPMCOUNTER15_CSR = 0xb0f,
      MHPMCOUNTER16_CSR = 0xb10,
      MHPMCOUNTER17_CSR = 0xb11,
      MHPMCOUNTER18_CSR = 0xb12,
      MHPMCOUNTER19_CSR = 0xb13,
      MHPMCOUNTER20_CSR = 0xb14,
      MHPMCOUNTER21_CSR = 0xb15,
      MHPMCOUNTER22_CSR = 0xb16,
      MHPMCOUNTER23_CSR = 0xb17,
      MHPMCOUNTER24_CSR = 0xb18,
      MHPMCOUNTER25_CSR = 0xb19,
      MHPMCOUNTER26_CSR = 0xb1a,
      MHPMCOUNTER27_CSR = 0xb1b,
      MHPMCOUNTER28_CSR = 0xb1c,
      MHPMCOUNTER29_CSR = 0xb1d,
      MHPMCOUNTER30_CSR = 0xb1e,
      MHPMCOUNTER31_CSR = 0xb1f,

      MCYCLEH_CSR = 0xb80,
      MINSTRETH_CSR = 0xb82,
      MHPMCOUNTER3H_CSR = 0xb83,
      MHPMCOUNTER4H_CSR = 0xb84,
      MHPMCOUNTER5H_CSR = 0xb85,
      MHPMCOUNTER6H_CSR = 0xb86,
      MHPMCOUNTER7H_CSR = 0xb87,
      MHPMCOUNTER8H_CSR = 0xb88,
      MHPMCOUNTER9H_CSR = 0xb89,
      MHPMCOUNTER10H_CSR = 0xb8a,
      MHPMCOUNTER11H_CSR = 0xb8b,
      MHPMCOUNTER12H_CSR = 0xb8c,
      MHPMCOUNTER13H_CSR = 0xb8d,
      MHPMCOUNTER14H_CSR = 0xb8e,
      MHPMCOUNTER15H_CSR = 0xb8f,
      MHPMCOUNTER16H_CSR = 0xb90,
      MHPMCOUNTER17H_CSR = 0xb91,
      MHPMCOUNTER18H_CSR = 0xb92,
      MHPMCOUNTER19H_CSR = 0xb93,
      MHPMCOUNTER20H_CSR = 0xb94,
      MHPMCOUNTER21H_CSR = 0xb95,
      MHPMCOUNTER22H_CSR = 0xb96,
      MHPMCOUNTER23H_CSR = 0xb97,
      MHPMCOUNTER24H_CSR = 0xb98,
      MHPMCOUNTER25H_CSR = 0xb99,
      MHPMCOUNTER26H_CSR = 0xb9a,
      MHPMCOUNTER27H_CSR = 0xb9b,
      MHPMCOUNTER28H_CSR = 0xb9c,
      MHPMCOUNTER29H_CSR = 0xb9d,
      MHPMCOUNTER30H_CSR = 0xb9e,
      MHPMCOUNTER31H_CSR = 0xb9f,

      // Machine counter setup.
      MHPMEVENT3_CSR = 0x323,
      MHPMEVENT4_CSR = 0x324,
      MHPMEVENT5_CSR = 0x325,
      MHPMEVENT6_CSR = 0x326,
      MHPMEVENT7_CSR = 0x327,
      MHPMEVENT8_CSR = 0x328,
      MHPMEVENT9_CSR = 0x329,
      MHPMEVENT10_CSR = 0x32a,
      MHPMEVENT11_CSR = 0x32b,
      MHPMEVENT12_CSR = 0x32c,
      MHPMEVENT13_CSR = 0x32d,
      MHPMEVENT14_CSR = 0x32e,
      MHPMEVENT15_CSR = 0x32f,
      MHPMEVENT16_CSR = 0x330,
      MHPMEVENT17_CSR = 0x331,
      MHPMEVENT18_CSR = 0x332,
      MHPMEVENT19_CSR = 0x333,
      MHPMEVENT20_CSR = 0x334,
      MHPMEVENT21_CSR = 0x335,
      MHPMEVENT22_CSR = 0x336,
      MHPMEVENT23_CSR = 0x337,
      MHPMEVENT24_CSR = 0x338,
      MHPMEVENT25_CSR = 0x339,
      MHPMEVENT26_CSR = 0x33a,
      MHPMEVENT27_CSR = 0x33b,
      MHPMEVENT28_CSR = 0x33c,
      MHPMEVENT29_CSR = 0x33d,
      MHPMEVENT30_CSR = 0x33e,
      MHPMEVENT31_CSR = 0x33f,

      // Supervisor mode registers.

      // Supervisor trap setup.
      SSTATUS_CSR = 0x100,
      SEDELEG_CSR = 0x102,
      SIDELEG_CSR = 0x103,
      SIE_CSR = 0x104,
      STVEC_CSR = 0x105,
      SCOUNTEREN_CSR = 0x106,
      // Supervisor Trap Handling 
      SSCRATCH_CSR = 0x140,
      SEPC_CSR = 0x141,
      SCAUSE_CSR = 0x142,
      STVAL_CSR = 0x143,
      SIP_CSR = 0x144,
      // Supervisor Protection and Translation 
      SATP_CSR = 0x180,

      // User mode registers.

      // User trap setup.
      USTATUS_CSR = 0x000,
      UIE_CSR = 0x004,
      UTVEC_CSR = 0x005,

      // User Trap Handling
      USCRATCH_CSR = 0x040,
      UEPC_CSR = 0x041,
      UCAUSE_CSR = 0x042,
      UTVAL_CSR = 0x043,
      UIP_CSR = 0x044,

      // User Floating-Point CSRs
      FFLAGS_CSR = 0x001,
      FRM_CSR = 0x002,
      FCSR_CSR = 0x003,

      // User Counter/Timers
      CYCLE_CSR = 0xc00,
      TIME_CSR = 0xc01,
      INSTRET_CSR = 0xc02,
      HPMCOUNTER3_CSR = 0xc03,
      HPMCOUNTER4_CSR = 0xc04,
      HPMCOUNTER5_CSR = 0xc05,
      HPMCOUNTER6_CSR = 0xc06,
      HPMCOUNTER7_CSR = 0xc07,
      HPMCOUNTER8_CSR = 0xc08,
      HPMCOUNTER9_CSR = 0xc09,
      HPMCOUNTER10_CSR = 0xc0a,
      HPMCOUNTER11_CSR = 0xc0b,
      HPMCOUNTER12_CSR = 0xc0c,
      HPMCOUNTER13_CSR = 0xc0d,
      HPMCOUNTER14_CSR = 0xc0e,
      HPMCOUNTER15_CSR = 0xc0f,
      HPMCOUNTER16_CSR = 0xc10,
      HPMCOUNTER17_CSR = 0xc11,
      HPMCOUNTER18_CSR = 0xc12,
      HPMCOUNTER19_CSR = 0xc13,
      HPMCOUNTER20_CSR = 0xc14,
      HPMCOUNTER21_CSR = 0xc15,
      HPMCOUNTER22_CSR = 0xc16,
      HPMCOUNTER23_CSR = 0xc17,
      HPMCOUNTER24_CSR = 0xc18,
      HPMCOUNTER25_CSR = 0xc19,
      HPMCOUNTER26_CSR = 0xc1a,
      HPMCOUNTER27_CSR = 0xc1b,
      HPMCOUNTER28_CSR = 0xc1c,
      HPMCOUNTER29_CSR = 0xc1d,
      HPMCOUNTER30_CSR = 0xc1e,
      HPMCOUNTER31_CSR = 0xc1f,

      CYCLEH_CSR = 0xc80,
      TIMEH_CSR = 0xc81,
      INSTRETH_CSR = 0xc82,
      HPMCOUNTER3H_CSR = 0xc83,
      HPMCOUNTER4H_CSR = 0xc84,
      HPMCOUNTER5H_CSR = 0xc85,
      HPMCOUNTER6H_CSR = 0xc86,
      HPMCOUNTER7H_CSR = 0xc87,
      HPMCOUNTER8H_CSR = 0xc88,
      HPMCOUNTER9H_CSR = 0xc89,
      HPMCOUNTER10H_CSR = 0xc8a,
      HPMCOUNTER11H_CSR = 0xc8b,
      HPMCOUNTER12H_CSR = 0xc8c,
      HPMCOUNTER13H_CSR = 0xc8d,
      HPMCOUNTER14H_CSR = 0xc8e,
      HPMCOUNTER15H_CSR = 0xc8f,
      HPMCOUNTER16H_CSR = 0xc90,
      HPMCOUNTER17H_CSR = 0xc91,
      HPMCOUNTER18H_CSR = 0xc92,
      HPMCOUNTER19H_CSR = 0xc93,
      HPMCOUNTER20H_CSR = 0xc94,
      HPMCOUNTER21H_CSR = 0xc95,
      HPMCOUNTER22H_CSR = 0xc96,
      HPMCOUNTER23H_CSR = 0xc97,
      HPMCOUNTER24H_CSR = 0xc98,
      HPMCOUNTER25H_CSR = 0xc99,
      HPMCOUNTER26H_CSR = 0xc9a,
      HPMCOUNTER27H_CSR = 0xc9b,
      HPMCOUNTER28H_CSR = 0xc9c,
      HPMCOUNTER29H_CSR = 0xc9d,
      HPMCOUNTER30H_CSR = 0xc9e,
      HPMCOUNTER31H_CSR = 0xc9f,

      // Debug/Trace registers.
      TSELECT_CSR = 0x7a0,
      TDATA1_CSR = 0x7a1,
      TDATA2_CSR = 0x7a2,
      TDATA3_CSR = 0x7a3,

      // Debug mode registers.
      DSCR_CSR = 0x7b0,
      DPC_CSR = 0x7b1,
      DSCRATCH_CSR = 0x7b2,

      MAX_CSR_ = MHARTID_CSR,   // csr with highest number
      MIN_CSR_ = USTATUS_CSR  // csr with smallest number
    };


  /// Model a control and status register. The template type URV
  /// (unsigned register value) is the type of the register value. It
  /// should be uint32_t for 32-bit implementattions and uint64_t for
  /// 64-bit.
  template <typename URV>
  struct Csr
  {
    Csr()
      : number_(CsrNumber(0)), valid_(false), value_(MIN_CSR_)
    { }

    Csr(const std::string& name, CsrNumber number, bool valid, URV value)
      : name_(name), number_(number), valid_(valid), value_(value)
    { }

    /// Return lowest privilige mode that can access the register.
    /// Bits 9 and 8 of the register number encode the privilge mode.
    PrivilegeMode privilegeMode() const
    { return PrivilegeMode((number_ & 0x300) >> 8); }

    /// Return true if register is read-only. Bits ten and eleven of
    /// the register number denote read-only when both one and read-write
    /// otherwise.
    bool isReadOnly() const
    { return (number_ & 0xc00) == 3; }

    std::string name_;
    CsrNumber number_;
    bool valid_;  // True if register is implemented
    URV value_;
  };


  /// Model the control and status register set.
  template <typename URV>
  class CsRegs
  {
  public:

    CsRegs();
    
    ~CsRegs();

    /// Set reg to a copy of the control-and-status description
    /// corresponding to the given name returning true on success. If
    /// no such name, return true leaving reg unmodified.
    bool findCsr(const std::string& name, Csr<URV>& reg) const;

    /// Set reg to a copy of the control-and-status description
    /// corresponding to the given name returning true on success. If
    /// no such name, return true leaving reg unmodified.
    bool findCsr(CsrNumber number, Csr<URV>& reg) const;

    /// Set value fo the value of the scr having the given number
    /// returning true on success.  Return false leaving value
    /// unmodified if there is no csr with the given number or if the
    /// csr is not valid or if the the given mode has no access to the
    /// register.
    bool read(CsrNumber number, PrivilegeMode mode, URV& value) const;

    /// Set the the csr having the given number to the given value
    /// returning true on success. Return false writing nothing if
    /// there is no csr with the given number or if the csr is not
    /// valid or if the given mode has no access to the register.
    bool write(CsrNumber number, PrivilegeMode mode, URV value);

  protected:

    /// Helper to construtor. Define machine-mode CSRs
    void defineMachineRegs();

    /// Helper to construtor. Define supervisor-mode CSRs
    void defineSupervisorRegs();

    /// Helper to construtor. Define user-mode CSRs
    void defineUserRegs();

    /// Helper to construtor. Define debug-mode CSRs
    void defineDebugRegs();

  private:

    std::vector< Csr<URV> > regs_;
    std::map<std::string, CsrNumber> nameToNumber_;
  };


  /// Structure used to unpack/pack the fields of the machine status
  /// register.
  template <typename URV>
  struct MstatusFields
  {
    MstatusFields(URV value = 0)
      : value_(value)
    { }

    union
    {
      URV value_;   // Machine status register.
      struct
      {
	unsigned SD       : 1;
	URV      res0     : sizeof(URV)*8 - 24;  // Reserved
	unsigned TSR      : 1;
	unsigned TW       : 1;
	unsigned TVM      : 1;
	unsigned MXR      : 1;
	unsigned SUM      : 1;
	unsigned MPRV     : 1;
	unsigned XS       : 2;
	unsigned FS       : 2;
	unsigned MPP      : 2;
	unsigned res1     : 2;
	unsigned SPP      : 1;
	unsigned MPIE     : 1;
	unsigned res2     : 1;
	unsigned SPIE     : 1;
	unsigned UPIE     : 1;
	unsigned MIE      : 1;
	unsigned res4     : 1;
	unsigned SIE      : 1;
	unsigned UIE      : 1;
      } fields_;
    };
  };
}