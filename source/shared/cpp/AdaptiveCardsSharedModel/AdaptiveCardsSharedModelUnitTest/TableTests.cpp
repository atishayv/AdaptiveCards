// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "stdafx.h"
#include "TableCell.h"

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
    };
}
