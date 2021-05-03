// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

namespace AdaptiveSharedNamespace
{
    class AdaptiveCardParseWarning;

    class ColumnDefinition
    {
    public:
        ColumnDefinition(const ColumnDefinition&) = default;
        ColumnDefinition(ColumnDefinition&&) = default;
        ColumnDefinition& operator=(const ColumnDefinition&) = default;
        ColumnDefinition& operator=(ColumnDefinition&&) = default;
        virtual ~ColumnDefinition() = default;

        HorizontalAlignment GetHorizontalCellContentAlignment() const;
        void SetHorizontalCellContentAlignment(HorizontalAlignment value);

        std::string GetWidth() const;
        void SetWidth(const std::string& value);
        void SetWidth(const std::string& value,
                      std::vector<std::shared_ptr<AdaptiveSharedNamespace::AdaptiveCardParseWarning>>* warnings);

        // explicit width takes precedence over relative width
        int GetPixelWidth() const;
        void SetPixelWidth(const int value);
    };
}
