#include <absl/status/status.h>
#include <absl/types/optional.h>
#include <memory>

#include "navigation.hpp"

struct XMBModel {
	std::shared_ptr<MenuElement> rootElement;
	std::shared_ptr<NavigationCursor> navigationCursor;
};
