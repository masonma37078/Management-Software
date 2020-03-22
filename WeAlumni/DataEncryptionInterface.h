#pragma once

/*
 * DataEncryptionInterface.h
 *
 * This file provide a basic data encrption algorithm for Encryption and Decryption.
 * Used on Admin management.
 *
 * @author: Hang Yuan
 * Revised: 3/21/20
 *
 */

#define KEY 200 // key must be larger than 154

namespace WeAlumni {
    using namespace System;
    public ref class DataEncryption
    {
    public:
        DataEncryption() {
            // Leave empty
        }

    protected:
        ~DataEncryption() {
            // Leave empty
        }

    public:
        int Encrypt(System::String^ plain);
    };

}