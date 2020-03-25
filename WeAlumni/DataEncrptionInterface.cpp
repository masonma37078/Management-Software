#pragma once
#include "DataEncryptionInterface.h"
#include <stdlib.h>
#include <string>

/*
 * DataEncryptionInterface.cpp
 *
 * This file provide a basic data encrption algorithm for Encryption only.
 * Used on Admin management.
 *
 * @author: Hang Yuan
 * Revised: 3/21/20
 *
 */

using namespace System;

/*
 * MarshalString
 * This method will convert a System::String^ to std::string.
 * @param System::String^ string needs to be converted
 * @return std::string string converted
 */
std::string MarshalString(String^ s) {
    using namespace Runtime::InteropServices;
    const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    std::string os = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));
    return os;
}

/*
 * Encrypt
 * This method will encrypt the given plain text into the cipher text by algorithm.
 * @param String^ plain text that will be encrypted
 * @return String^ cipher text that is encrpyted
 */
int WeAlumni::DataEncryption::Encrypt(String^ plain) {
    std::string plainText = MarshalString(plain);
    std::hash<std::string> str_hash;
    return (int)str_hash(plainText);
}