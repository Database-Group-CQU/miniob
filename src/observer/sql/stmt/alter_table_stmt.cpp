/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2023/6/13.
//

#include "sql/stmt/alter_table_stmt.h"
#include "event/sql_debug.h"

RC AlterTableStmt::alter(Db *db, const AlterTableSqlNode &alter_table, Stmt *&stmt)
{
  stmt = new AlterTableStmt(alter_table.relation_name);
  sql_debug("alter table statement: table name %s", alter_table.relation_name.c_str());
  return RC::SUCCESS;
}