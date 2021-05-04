// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include "pch.h"
#include "BaseCardElement.h"

namespace AdaptiveSharedNamespace
{
    class TableColumnDefinition;
    class TableRow;

    class Table : public BaseCardElement
    {
    public:
        Table();
        Table(const Table&) = default;
        Table(Table&&) = default;
        Table& operator=(const Table&) = default;
        Table& operator=(Table&&) = default;
        virtual ~Table() = default;

        std::string Serialize() const override;
        Json::Value SerializeToJsonValue() const override;

        bool GetShowGridLines() const;
        void SetShowGridLines(bool value);

        bool GetFirstRowAsHeaders() const;
        void SetFirstRowAsHeaders(bool value);

        HorizontalAlignment GetHorizontalCellContentAlignment() const;
        void SetHorizontalCellContentAlignment(HorizontalAlignment value);

        VerticalAlignment GetVerticalCellContentAlignment() const;
        void SetVerticalCellContentAlignment(VerticalAlignment value);

        const std::vector<std::shared_ptr<TableColumnDefinition>>& GetColumns() const;
        void SetColumns(const std::vector<std::shared_ptr<TableColumnDefinition>>& value);

        std::vector<std::shared_ptr<TableRow>>& GetRows();
        const std::vector<std::shared_ptr<TableRow>>& GetRows() const;
        void SetRows(const std::vector<std::shared_ptr<TableRow>>& value);

    private:
        bool m_showGridLines;
        bool m_firstRowAsHeaders;
        HorizontalAlignment m_horizontalCellContentAlignment;
        VerticalAlignment m_verticalCellContentAlignment;

        std::vector<std::shared_ptr<TableColumnDefinition>> m_columnDefinitions;
        std::vector<std::shared_ptr<TableRow>> m_rows;
    };
}
