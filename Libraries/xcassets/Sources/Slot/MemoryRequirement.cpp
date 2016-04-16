/* Copyright 2013-present Facebook. All Rights Reserved. */

#include <xcassets/Slot/MemoryRequirement.h>

using xcassets::Slot::MemoryRequirement;
using xcassets::Slot::MemoryRequirements;

ext::optional<MemoryRequirement> MemoryRequirements::
Parse(std::string const &value)
{
    if (value == "1GB") {
        return MemoryRequirement::Minimum1GB;
    } else if (value == "2GB") {
        return MemoryRequirement::Minimum2GB;
    } else if (value == "4GB") {
        return MemoryRequirement::Minimum4GB;
    } else {
        fprintf(stderr, "warning: unknown memory requirement %s\n", value.c_str());
        return ext::nullopt;
    }
}

std::string MemoryRequirements::
String(MemoryRequirement memoryRequirement)
{
    switch (memoryRequirement) {
        case MemoryRequirement::Minimum1GB:
            return "1GB";
        case MemoryRequirement::Minimum2GB:
            return "2GB";
        case MemoryRequirement::Minimum4GB:
            return "4GB";
    }
}