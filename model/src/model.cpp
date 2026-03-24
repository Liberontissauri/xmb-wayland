#include "model.hpp"
#include "absl/log/check.h"
#include <memory>


NavigationCursor::NavigationCursor(std::shared_ptr<XMBTree> tree) : tree(tree) {}

absl::StatusOr<std::shared_ptr<MenuElement>> NavigationCursor::getCurrentElement() const {
	return tree->getElementAtPath(elementPath);
}

int NavigationCursor::getCurrentMenuIndex() const {
	CHECK_GT(elementPath.size(), 0) << "Element path size needs to be greater than 0.";
	return elementPath.back();
}
