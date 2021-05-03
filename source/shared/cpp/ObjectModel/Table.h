// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include "pch.h"
#include "BaseCardElement.h"

namespace AdaptiveSharedNamespace
{
    class ColumnDefinition;
    class TableRow;

    class Table : public BaseCardElement
    {
    public:
        Table(const Table&) = default;
        Table(Table&&) = default;
        Table& operator=(const Table&) = default;
        Table& operator=(Table&&) = default;
        virtual ~Table() = default;

        std::string Serialize() const override;
        Json::Value SerializeToJsonValue() const override;

        //void DeserializeChildren(ParseContext& context, const Json::Value& value) override;

        bool GetShowGridLines() const;
        void SetShowGridLines(bool value);

        bool GetFirstRowAsHeaders() const;
        void SetFirstRowAsHeaders(bool value);

        VerticalAlignment GetVerticalCellContentAlignment() const;
        void SetVerticalCellContentAlignment(VerticalAlignment value);

        HorizontalAlignment GetHorizontalCellContentAlignment() const;
        void SetHorizontalCellContentAlignment(HorizontalAlignment value);

        std::vector<std::shared_ptr<ColumnDefinition>>& GetColumns();
        const std::vector<std::shared_ptr<ColumnDefinition>>& GetColumns() const;
        void SetColumns(const std::vector<std::shared_ptr<ColumnDefinition>>& value);

        std::vector<std::shared_ptr<TableRow>>& GetTableRows();
        const std::vector<std::shared_ptr<TableRow>>& GetTableRows() const;
        void SetTableRows(const std::vector<std::shared_ptr<TableRow>>& value);

    };
}
