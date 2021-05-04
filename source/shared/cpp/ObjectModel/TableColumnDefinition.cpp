// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "pch.h"
#include "TableColumnDefinition.h"
#include "Util.h"

namespace AdaptiveSharedNamespace
{
    TableColumnDefinition::TableColumnDefinition() :
        m_horizontalCellContentAlignment(HorizontalAlignment::Left), m_verticalCellContentAlignment(VerticalAlignment::Top)
    {
    }

    std::string TableColumnDefinition::Serialize() { return ParseUtil::JsonToString(SerializeToJsonValue()); }

    Json::Value TableColumnDefinition::SerializeToJsonValue()
    {
        Json::Value root;

        if (m_horizontalCellContentAlignment != HorizontalAlignment::Left)
        {
            root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::HorizontalCellContentAlignment)] =
                HorizontalAlignmentToString(m_horizontalCellContentAlignment);
        }

        if (m_verticalCellContentAlignment != VerticalAlignment::Top)
        {
            root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::VerticalCellContentAlignment)] =
                VerticalAlignmentToString(m_verticalCellContentAlignment);
        }

        if (m_width.has_value())
        {
            root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Width)] = m_width.value();
        }

        if (m_pixelWidth.has_value())
        {
            std::ostringstream pixelStr;
            pixelStr << m_pixelWidth.value() << "px";
            root[AdaptiveCardSchemaKeyToString(AdaptiveCardSchemaKey::Width)] = pixelStr.str();
        }

        return root;
    }

    HorizontalAlignment TableColumnDefinition::GetHorizontalCellContentAlignment() const
    {
        return m_horizontalCellContentAlignment;
    }

    void TableColumnDefinition::SetHorizontalCellContentAlignment(HorizontalAlignment value)
    {
        m_horizontalCellContentAlignment = value;
    }

    VerticalAlignment TableColumnDefinition::GetVerticalCellContentAlignment() const
    {
        return m_verticalCellContentAlignment;
    }

    void TableColumnDefinition::SetVerticalCellContentAlignment(VerticalAlignment value)
    {
        m_verticalCellContentAlignment = value;
    }

    std::optional<unsigned int> TableColumnDefinition::GetWidth() const { return m_width; }

    void TableColumnDefinition::SetWidth(const std::optional<unsigned int>& value)
    {
        m_pixelWidth = {};
        m_width = value;
    }

    std::optional<unsigned int> TableColumnDefinition::GetPixelWidth() const { return m_pixelWidth; }

    void TableColumnDefinition::SetPixelWidth(const std::optional<unsigned int>& value)
    {
        m_width = {};
        m_pixelWidth = value;
    }

    std::shared_ptr<TableColumnDefinition> TableColumnDefinition::Deserialize(ParseContext& context, const Json::Value& json)
    {
        auto tableColumnDefinition = std::make_shared<TableColumnDefinition>();

        tableColumnDefinition->SetHorizontalCellContentAlignment(ParseUtil::GetEnumValue<HorizontalAlignment>(
            json, AdaptiveCardSchemaKey::HorizontalCellContentAlignment, HorizontalAlignment::Left, HorizontalAlignmentFromString));
        tableColumnDefinition->SetVerticalCellContentAlignment(ParseUtil::GetEnumValue<VerticalAlignment>(
            json, AdaptiveCardSchemaKey::VerticalCellContentAlignment, VerticalAlignment::Top, VerticalAlignmentFromString));

        auto widthValue = ParseUtil::ExtractJsonValue(json, AdaptiveCardSchemaKey::Width, false);
        if (!widthValue.empty())
        {
            if (widthValue.isInt())
            {
                tableColumnDefinition->SetWidth(widthValue.asInt());
            }
            else if (widthValue.isString())
            {
                tableColumnDefinition->SetPixelWidth(ParseSizeForPixelSize(widthValue.asString(), &(context.warnings)));
            }
            else
            {
                 context.warnings.emplace_back(std::make_shared<AdaptiveCardParseWarning>(WarningStatusCode::InvalidValue, "Invalid type for \"width\""));
            }
        }

        return tableColumnDefinition;
    }

    std::shared_ptr<TableColumnDefinition> TableColumnDefinition::DeserializeFromString(ParseContext& context,
                                                                                        const std::string& jsonString)
    {
        return Deserialize(context, ParseUtil::GetJsonValueFromString(jsonString));
    }
}
