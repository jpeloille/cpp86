//
// Created by jpeloille on 4/4/21.
//

#ifndef X86___IAPX86_H
#define X86___IAPX86_H


class iapx86
{
private:
    uint8_t (iapx86::*instDecoder[0xFF])();

/* Instructions set methods */
private:
    /*
     * Mnemonic notation :
     * ib : immediate byte         rb : register byte
     * iw : immediate word         rw : register word
     * mb : memory byte            rmb : register or memory byte
     * mw : memory word            rmb : register or memory byte
     * sr : segment register
     */

    uint8_t add_rmb_rb();
    uint8_t add_rmw_rw();
    uint8_t add_rb_rmb();
    uint8_t add_rw_rmw();
    uint8_t add_AL_ib();
    uint8_t add_AX_iw();
    uint8_t mov_AL_ib();
    uint8_t mov_rmw_sr();
    uint8_t mov_sr_rmw();

    uint8_t JMP_NEAR_RELATIVE();
    uint8_t JMP_NEAR_INDIRECT();
    uint8_t JMP_FAR_DIRECT();
    uint8_t JMP_FAR_INDIRECT();

/* Arithmetics methods */
private:
    uint8_t Add8(uint8_t leftOpernad, uint8_t righrOperand);

private:
    void decode_ModRM();

    // R/W directly to the selected register //
    inline uint8_t ReadByte_Register();
    inline uint16_t ReadWord_Register();
    void WriteByte_Register(uint8_t data);
    void WriteWord_Register(uint16_t data);

    // R/W switching Effective Address //
    inline uint8_t ReadByte_EffectiveAddress();
    inline uint16_t ReadWord_EffectiveAddress();

    // R/W to memory using Physical Address //
    uint8_t ReadByte_Memory(uint32_t physicalAddress);
    uint16_t ReadWord_Memory(uint32_t physicalAddress);

    uint8_t  getImmediateByte();
    uint16_t getImmediateWord();



    static int loadbios();


public:
    iapx86();
    ~iapx86();

    void cpuReset();
    void exec86(int requestedCycles);
};

#endif //X86___IAPX86_H
