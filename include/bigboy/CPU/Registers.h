#ifndef BIGBOY_REGISTERS_H
#define BIGBOY_REGISTERS_H

#include <bigboy/CPU/Flags.h>

enum class RegisterOperand : uint8_t {
    B, // 000
    C, // 001
    D, // 010
    E, // 011
    H, // 100
    L, // 101
    A  // 111
};

enum class RegisterPairOperand : uint8_t {
    BC, // 00
    DE, // 01
    HL, // 10
    SP  // 11
};

enum class RegisterPairStackOperand : uint8_t {
    BC, // 00
    DE, // 01
    HL, // 10
    AF  // 11
};

struct Registers {
    // General purpose
    #ifdef BIGBOY_BIG_ENDIAN
    uint8_t b = 0;
    uint8_t c = 0;
    #else
    uint8_t c = 0;
    uint8_t b = 0;
    #endif

    #ifdef BIGBOY_BIG_ENDIAN
    uint8_t d = 0;
    uint8_t e = 0;
    #else
    uint8_t e = 0;
    uint8_t d = 0;
    #endif

    #ifdef BIGBOY_BIG_ENDIAN
    uint8_t h = 0;
    uint8_t l = 0;
    #else
    uint8_t l = 0;
    uint8_t h = 0;
    #endif

    // Accumulator and flags
    #ifdef BIGBOY_BIG_ENDIAN
    uint8_t a = 0;
    uint8_t f = 0;
    #else
    uint8_t f = 0;
    uint8_t a = 0;
    #endif

    // Stack pointer
    uint16_t sp = 0xFF - 1;

    uint8_t& get(RegisterOperand target);
    uint16_t& get(RegisterPairOperand target);
    uint16_t& get(RegisterPairStackOperand target);

    // Some instructions allow two 8 bit registers to be read as one 16 bit register
    // Referred to as BC (B & C), DE (D & E), HL (H & L) and AF (A & F)
    uint16_t& BC();
    uint16_t BC() const;

    uint16_t& DE();
    uint16_t DE() const;

    uint16_t& HL();
    uint16_t HL() const;

    uint16_t& AF();
    uint16_t AF() const;

    void reset();
};

#endif //BIGBOY_REGISTERS_H
