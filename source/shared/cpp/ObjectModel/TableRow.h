// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

namespace AdaptiveSharedNamespace
{
    class TableCell;

    class TableRow
    {
    public:
        TableRow(const TableRow&) = default;
        TableRow(TableRow&&) = default;
        TableRow& operator=(const TableRow&) = default;
        TableRow& operator=(TableRow&&) = default;
        virtual ~TableRow() = default;

        std::vector<std::shared_ptr<TableCell>>& GetCells();
        const std::vector<std::shared_ptr<TableCell>>& GetCells() const;
        void SetCells(const std::vector<std::shared_ptr<TableCell>>& value);

        VerticalAlignment GetVerticalCellContentAlignment() const;
        void SetVerticalCellContentAlignment(VerticalAlignment value);

        HorizontalAlignment GetHorizontalCellContentAlignment() const;
        void SetHorizontalCellContentAlignment(HorizontalAlignment value);

        ContainerStyle GetStyle() const;
        void SetStyle(const ContainerStyle value);
    };
}
