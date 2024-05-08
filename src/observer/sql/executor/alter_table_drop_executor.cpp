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

#include "sql/executor/alter_table_drop_executor.h"

#include "common/log/log.h"
#include "event/session_event.h"
#include "event/sql_event.h"
#include "session/session.h"
#include "sql/stmt/alter_table_stmt.h"
#include "storage/db/db.h"

RC AlterTableDropAttrExecutor::execute(SQLStageEvent *sql_event)
{
  Stmt    *stmt    = sql_event->stmt();
  Session *session = sql_event->session_event()->session();
  ASSERT(stmt->type() == StmtType::ALTER_TABLE_DROP_ATTR,
      "alter table executor can not run this command: %d",
      static_cast<int>(stmt->type()));

  AlterTableDropAttrStmt *alter_table_drop_attr_stmt = static_cast<AlterTableDropAttrStmt *>(stmt);

  const char *table_name = alter_table_drop_attr_stmt->table_name().c_str();
  RC rc = session->get_current_db()->alter_table_drop(table_name, alter_table_drop_attr_stmt->attr_name());

  return rc;
}