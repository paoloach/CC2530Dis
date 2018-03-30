//
// Created by paolo on 23/03/18.
//
#include <sstream>
#include <iostream>
#include <iomanip>
#include "DirectName.h"

static const char *IEN0_BITS[8] = {"RFERRIE", "ADCIE", "URX0IE", "URX1IE", "ENCIE", "STIE", "reserved", "EA"};
static const char *S0CON_BITS[8] = {"ENCIF_0", "ENCIF_1", "reserved", "reserved", "reserved", "reserved", "reserved", "reserved"};

std::string DirectName::toString(uint8_t value) {
    std::stringstream stream;
    switch (value) {
        case 0x00 ... 0x07:
            return "R" + std::to_string(value);
        case 0x08 ... 0x0F:
            stream << "V"  << std::hex << (uint32_t)(value-8);
            return stream.str();
        case 0x15:
            return "SP";
        case 0x18:
            return "XSP(L)";
        case 0x19:
            return "XSP(H)";
        case 0x20:
            return "VB";
        case 0xB4:
            return "ADCCON1";
        case 0xB5:
            return "ADCCON2";
        case 0xB6:
            return "ADCCON3";
        case 0xBA:
            return "ADCL";
        case 0xBB:
            return "ADCH";
        case 0xBC:
            return "RNLD";
        case 0xBD:
            return "RNLH";
        case 0xB1:
            return "ENCDI";
        case 0xB2:
            return "ENCDO";
        case 0xB3:
            return "ENCCS";
        case 0x80:
            return "P0";
        case 0x81:
            return "SP";
        case 0x82:
            return "DPL0";
        case 0x83:
            return "DPH0";
        case 0x84:
            return "DPH1";
        case 0x85:
            return "DPH1";
        case 0x87:
            return "PCON";
        case 0x88:
            return "TCON";
        case 0x90:
            return "P1";
        case 0x92:
            return "DPS";
        case 0x98:
            return "S0CON";
        case 0x9A:
            return "IEN2";
        case 0x9B:
            return "S1CON";
        case 0xA0:
            return "P2";
        case 0xA8:
            return "IEN0";
        case 0xA9:
            return "IP0";
        case 0xB8:
            return "IEN1";
        case 0xB9:
            return "IP1";
        case 0xC0:
            return "IRCON";
        case 0xD0:
            return "PSW";
        case 0xE0:
            return "A";
        case 0xE8:
            return "IRCON2";
        case 0xF0:
            return "B";
        case 0xD1:
            return "DMAIRQ";
        case 0xD2:
            return "DMA1CFGL";
        case 0xD3:
            return "DMA1CFGH";
        case 0xD4:
            return "DM0CFGL";
        case 0xD5:
            return "DMA0CFGH";
        case 0xD6:
            return "DMAARM";
        case 0xD7:
            return "DMAREQ";
        case 0x89:
            return "P0IFG";
        case 0x8A:
            return "P1IFG";
        case 0x8B:
            return "P2IFG";
        case 0x8C:
            return "PICTL";
        case 0xAB:
            return "P0IEN";
        case 0x8D:
            return "P1IEN";
        case 0xAC:
            return "P2IEN";
        case 0x8F:
            return "P0INP";
        case 0xF1:
            return "PERCFG";
        case 0xF2:
            return "APCFG";
        case 0xF3:
            return "P0SEL";
        case 0xF4:
            return "P1SEL";
        case 0xF5:
            return "P2SEL";
        case 0xF6:
            return "P1INP";
        case 0xF7:
            return "P2INP";
        case 0xFD:
            return "P0DIR";
        case 0xFE:
            return "P1DIR";
        case 0xFF:
            return "P2DIR";
        case 0xAE:
            return "PMUX";
        case 0x93:
            return "MPAGE";
        case 0xC7:
            return "MEMCTL";
        case 0x9F:
            return "FMAP";
        case 0x91:
            return "RFIRQF1";
        case 0xD9:
            return "RFD";
        case 0xE1:
            return "RFST";
        case 0xE9:
            return "RFIRQF0";
        case 0xBF:
            return "RFERRF";
        case 0x95:
            return "ST0";
        case 0x96:
            return "ST1";
        case 0x97:
            return "ST2";
        case 0xAD:
            return "STLOAD";
        case 0xBE:
            return "SLEEPCMD";
        case 0x9D:
            return "SLEEPSTA";
    }


    stream << std::setfill('0') << std::setw(2) << std::hex << (uint32_t) value;
    return stream.str();
}

std::string DirectName::bitToString(uint8_t value) {
    std::stringstream stream;
    if (value < 0x80) {
        stream << std::setfill('0') << std::setw(2) << std::hex << (uint32_t) value;
    } else {
        if (value >= 0x80 && value <= 0x87) {
            stream << "P0.bit" << (uint16_t) (value & 0x07);
        } else if (value >= 0xA8 & value <= 0xAF) {
            stream << "IEN0." << IEN0_BITS[value & 0x07];
        } else if (value >= 0x90 & value <= 0x97) {
            stream << "P1.bit" << (uint16_t) (value & 0x07);
        } else if (value >= 0x98 & value <= 0x9F) {
            stream << "S0CON.bit" << S0CON_BITS[value & 0x07];
        } else if (value >= 0xA0 & value <= 0xA7) {
            stream << "P2.bit" << (uint16_t) (value & 0x07);
        } else if (value >= 0xE0 & value <= 0xE8) {
            stream << "A.bit" << (uint16_t) (value & 0x07);
        } else {
            stream << std::setfill('0') << std::setw(2) << std::hex << (uint32_t) value;
        }
    }
    return stream.str();
}
