#pragma once
#include "Database.h"
#include "DatabasePrecheckPrompt.h"

/*
 * DatabasePrecheck.h
 *
 * This file provide method to do DB precheck
 *
 * @author: Xiangdong Che, Yiyun Zheng
 * Revised: 04/09/20
  *         04/11/20 Add check treasury database
 *
 */

namespace WeAlumni {
    public ref class DatabasePrecheck {

    public:
        static bool CheckAdmin();
        static bool CheckData();
        static bool CheckTre();
        static void StartPrecheck();
        static bool TrePrecheck();
    };
}