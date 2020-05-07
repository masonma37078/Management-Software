#pragma once

/*
 * PublicUserInfo.h
 *
 * This file defined a public class to all pages that contain the current user info.
 * The instance of PublicUserInfo should be decleared in Login page.
 *
 * @author: Hang Yuan
 * Revised: 4/4/20
 *
 */

namespace WeAlumni {
    using namespace System;

    public ref class PublicUserInfo
    {
    public:

        enum class Auth
        {
            Level_1,
            Level_2,
            Level_3,
            Level_4,
            Level_5
        };
        PublicUserInfo() {

        }

        PublicUserInfo(int id, String^ name, Auth auth) {
            _id = id;
            _name = name;
            _auth = auth;
        }

    protected:
        ~PublicUserInfo()
        {

        }

    private:
        int _id;
        String^ _name;
        Auth _auth;

    public:
        int GetId() { return _id; }
        String^ GetName() { return _name; }
        Auth GetAuth() { return _auth; }
        String^ GetAuthName() {
            if (_auth == Auth::Level_1) return "Level-1";
            if (_auth == Auth::Level_2) return "Level-2";
            if (_auth == Auth::Level_3) return "Level-3";
            if (_auth == Auth::Level_4) return "Level-4";
            if (_auth == Auth::Level_5) return "Level-5";
            return "Î´ÖªÈ¨ÏÞ";
        };
        void SetId(int id) { _id = id; }
        void SetName(String^ name) { _name = name; }
        void SetAuth(Auth auth) { _auth = auth; }
    };
}