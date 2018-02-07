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

#include <WCDB/lang.h>

copy_on_write_string LangColumnConstraint::SQL() const
{
    std::string description;
    if (!name.empty()) {
        description.append("CONSTRAINT " + name.get());
    }
    description.append(" ");
    switch (type) {
        case Type::PrimaryKey:
            description.append("PRIMARY KEY ");
            if (order != LangOrder::NotSet) {
                description.append(LangOrderName(order));
                description.append(" ");
            }
            if (conflictClause != LangConflictClause::NotSet) {
                description.append(LangConflictClauseName(conflictClause));
                description.append(" ");
            }
            if (autoIncrement) {
                description.append("AUTOINCREMENT");
            }
            break;
        case Type::NotNull:
            description.append("NOT NULL ");
            if (conflictClause != LangConflictClause::NotSet) {
                description.append(LangConflictClauseName(conflictClause));
                description.append(" ");
            }
            break;
        case Type::Unique:
            description.append("UNIQUE ");
            if (conflictClause != LangConflictClause::NotSet) {
                description.append(LangConflictClauseName(conflictClause));
                description.append(" ");
            }
            break;
        case Type::Check:
            assert(!expr.empty());
            description.append("CHECK(" + expr.description().get() + ")");
            break;
        case Type::Default:
            description.append("DEFAULT ");
            switch (defaultSwitcher) {
                case DefaultSwitch::LiteralValue:
                    assert(!literalValue.empty());
                    description.append(literalValue.description().get());
                    break;
                case DefaultSwitch::Expr:
                    assert(!expr.empty());
                    description.append("(" + expr.description().get() + ")");
                    break;
            }
            break;
        case Type::Collate:
            assert(!collationName.empty());
            description.append("COLLATE " + collationName.get());
            break;
        case Type::ForeignKeyClause:
            assert(!foreignKeyClause.empty());
            description.append(foreignKeyClause.description().get());
            break;
    }
    return description;
}
