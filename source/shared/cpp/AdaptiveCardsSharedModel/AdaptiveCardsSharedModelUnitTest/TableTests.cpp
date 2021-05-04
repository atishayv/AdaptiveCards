// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "stdafx.h"
#include "TableCell.h"
#include "TableRow.h"
#include "TableColumnDefinition.h"
#include "ParseContext.h"
#include "ParseUtil.h"

using namespace std::string_literals;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdaptiveCards;

namespace AdaptiveCardsSharedModelUnitTest
{
    TEST_CLASS(TableTests)
    {
    public:
        TEST_METHOD(TableCellInstantiate)
        {
            auto cell = std::make_shared<AdaptiveCards::TableCell>();
            auto serializedCell = cell->Serialize();
            Assert::AreEqual("{\"items\":[],\"type\":\"TableCell\"}\n"s, serializedCell);
        }

        TEST_METHOD(TableCellParse)
        {
            std::string tableCellFragment {R"(
            {
                "type": "TableCell",
                "items": [
                    {
                        "type": "TextBlock",
                        "text": "flim"
                    }
                ],
                "rtl": true
            })"};

            ParseContext context{};
            auto parser = std::make_shared<AdaptiveCards::TableCellParser>();
            auto tableCell = std::static_pointer_cast<TableCell>(parser->DeserializeFromString(context, tableCellFragment));

            auto rtl = tableCell->GetRtl();
            Assert::IsTrue(rtl.has_value());
            Assert::IsTrue(rtl.value());

            auto items = tableCell->GetItems();
            Assert::AreEqual(1ui64, items.size());

            auto serializedResult = tableCell->Serialize();
            Assert::AreEqual("{\"items\":[{\"text\":\"flim\",\"type\":\"TextBlock\"}],\"rtl\":true,\"type\":\"TableCell\"}\n"s, serializedResult);
        }

        TEST_METHOD(TableRowParse)
        {
            std::string tableRowFragment { R"(
            {
                "type": "TableRow",
                "horizontalCellContentAlignment": "center",
                "verticalCellContentAlignment": "bottom",
                "style": "accent",
                "cells": [
                    {
                        "type": "TableCell",
                        "items": [
                            {
                                "type": "TextBlock",
                                "text": "the first"
                            },
                            {
                                "type": "TextBlock",
                                "text": "the first part deux"
                            }
                        ],
                        "rtl": true
                    },
                    {
                        "type": "TableCell",
                        "items": [
                            {
                                "type": "TextBlock",
                                "text": "the second"
                            }
                        ],
                        "rtl": true
                    }
                ]
            })"};

            ParseContext context{};
            auto parser = std::make_shared<AdaptiveCards::TableRowParser>();
            auto tableRow = std::static_pointer_cast<TableRow>(parser->DeserializeFromString(context, tableRowFragment));

            Assert::AreEqual(2ui64, tableRow->GetCells().size());
            Assert::IsTrue(ContainerStyle::Accent == tableRow->GetStyle());
            Assert::IsTrue(HorizontalAlignment::Center == tableRow->GetHorizontalCellContentAlignment());
            Assert::IsTrue(VerticalAlignment::Bottom == tableRow->GetVerticalCellContentAlignment());

            auto serializedResult = tableRow->Serialize();

            Assert::AreEqual("{\"cells\":[{\"items\":[{\"text\":\"the first\",\"type\":\"TextBlock\"},{\"text\":\"the first part deux\",\"type\":\"TextBlock\"}],\"rtl\":true,\"type\":\"TableCell\"},{\"items\":[{\"text\":\"the second\",\"type\":\"TextBlock\"}],\"rtl\":true,\"type\":\"TableCell\"}],\"horizontalCellContentAlignment\":\"center\",\"style\":\"Accent\",\"type\":\"TableRow\",\"verticalCellContentAlignment\":\"bottom\"}\n"s, serializedResult);
        }

        TEST_METHOD(TableColumnDefinitionSimpleParse)
        {
            std::string columnDefinitionFragment = R"(
                {
                    "horizontalCellContentAlignment": "center",
                    "verticalCellContentAlignment": "bottom",
                    "width": 1
                })";

            ParseContext context{};
            auto columnDefinition = TableColumnDefinition::DeserializeFromString(context, columnDefinitionFragment);

            auto width = columnDefinition->GetWidth();
            Assert::IsTrue(width.has_value());
            Assert::IsTrue(1 == width.value());

            Assert::IsFalse(columnDefinition->GetPixelWidth().has_value());
            Assert::IsTrue(HorizontalAlignment::Center == columnDefinition->GetHorizontalCellContentAlignment());
            Assert::IsTrue(VerticalAlignment::Bottom == columnDefinition->GetVerticalCellContentAlignment());

            auto serializedResult = columnDefinition->Serialize();
            Assert::AreEqual("{\"horizontalCellContentAlignment\":\"center\",\"verticalCellContentAlignment\":\"bottom\",\"width\":1}\n"s, serializedResult);
        }

        TEST_METHOD(TableColumnDefinitionPixelParse)
        {
            std::string columnDefinitionFragment = R"(
                {
                    "horizontalCellContentAlignment": "right",
                    "verticalCellContentAlignment": "center",
                    "width": "100px"
                })";

            ParseContext context{};
            auto columnDefinition = TableColumnDefinition::DeserializeFromString(context, columnDefinitionFragment);

            auto width = columnDefinition->GetWidth();
            Assert::IsFalse(width.has_value());

            auto pixelWidth = columnDefinition->GetPixelWidth();
            Assert::IsTrue(pixelWidth.has_value());
            Assert::IsTrue(100 == pixelWidth.value());
            Assert::IsTrue(HorizontalAlignment::Right == columnDefinition->GetHorizontalCellContentAlignment());
            Assert::IsTrue(VerticalAlignment::Center == columnDefinition->GetVerticalCellContentAlignment());

            auto serializedResult = columnDefinition->Serialize();
            Assert::AreEqual("{\"horizontalCellContentAlignment\":\"right\",\"verticalCellContentAlignment\":\"center\",\"width\":\"100px\"}\n"s, serializedResult);
        }

    };
}
