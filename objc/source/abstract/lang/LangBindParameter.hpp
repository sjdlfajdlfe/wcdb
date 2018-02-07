/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef LangBindParameter_hpp
#define LangBindParameter_hpp

#include <WCDB/lang_common.h>

class LangBindParameter : public Lang {
public:
    enum class Type : int {
        QuestionMark,
        QuestionMarkWithNumber,
        Colon,
        At,
        DollarSign,
    };
    Type type;
    int n;
    copy_on_write_string name;

    virtual copy_on_write_string SQL() const;
};

#endif /* LangBindParameter_hpp */
