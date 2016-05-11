/*
 * PropertyMap.h
 *
 *  Created on: Jul 13, 2015
 *      Author: ahueck
 */

#ifndef CORE_ISSUE_MAP_PROPERTYMAP_H
#define CORE_ISSUE_MAP_PROPERTYMAP_H

#include "PropertyMacros.h"
#include "Value.h"

#include <map>

namespace opov {

typedef std::map<std::string, Value> property_map;

// creates a getter and setter using a std::map<std::string, Value> called
// _properties as the property store
#define IssueProperty(NAME)                                               \
  _as DS_CONCAT(NAME, PropertyType);                                      \
  void DS_CONCAT(set, NAME)(DS_CONCAT(NAME, PropertyType) value) {        \
    _properties[DS_STRINGIFY(NAME)] = Value(value);                       \
  }                                                                       \
  DS_CONCAT(NAME, PropertyType) DS_CONCAT(get, NAME)() const {            \
    auto it = _properties.find(DS_STRINGIFY(NAME));                       \
    if (it == std::end(_properties))                                      \
      return PropertyType<DS_CONCAT(NAME, PropertyType)>::DefaultValue(); \
    return it->second.get<DS_CONCAT(NAME, PropertyType)>();               \
  }

} /* namespace opov */

#endif  // CORE_ISSUE_MAP_PROPERTYMAP_H
