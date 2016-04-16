/* Copyright 2013-present Facebook. All Rights Reserved. */

#ifndef __xcassets_Asset_GCDashboardImage_h
#define __xcassets_Asset_GCDashboardImage_h

#include <xcassets/Asset/Asset.h>
#include <xcassets/ContentReference.h>
#include <plist/Dictionary.h>

#include <memory>
#include <string>
#include <vector>
#include <ext/optional>

namespace xcassets {
namespace Asset {

class ImageSet;

class GCDashboardImage : public Asset {
private:
    ext::optional<ContentReference>        _contentReference;
    std::vector<std::shared_ptr<ImageSet>> _children;

private:
    friend class Asset;
    using Asset::Asset;

public:
    ext::optional<ContentReference> const &contentReference() const
    { return _contentReference; }
    std::vector<std::shared_ptr<ImageSet>> children() const
    { return _children; }

public:
    static AssetType Type()
    { return AssetType::GCDashboardImage; }
    virtual AssetType type()
    { return AssetType::GCDashboardImage; }

public:
    static ext::optional<std::string> Extension()
    { return std::string("gcdashboardimage"); }

protected:
    virtual bool parse(plist::Dictionary const *dict, std::unordered_set<std::string> *seen, bool check);
};

}
}

#endif // !__xcassets_Asset_GCDashboardImage_h
