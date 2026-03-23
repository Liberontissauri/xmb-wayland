#include "model.hpp"
#include "absl/log/check.h"
#include <memory>


NavigationCursor::NavigationCursor(std::shared_ptr<MenuElement> rootElement) : rootElement(rootElement) {}

absl::StatusOr<std::shared_ptr<MenuElement>> NavigationCursor::getCurrentElement() const {
	std::shared_ptr<MenuElement> currentElement = rootElement;
	for (int index : elementPath) {
		if (!currentElement->children.has_value() || index >= currentElement->children->size()) {
			return absl::NotFoundError("Invalid path: index path out of bounds at index " + std::to_string(index));
		}
		currentElement = (*currentElement->children)[index];
	}
	return currentElement;
}

int NavigationCursor::getCurrentMenuIndex() const {
	CHECK_GT(elementPath.size(), 0) << "Element path size needs to be greater than 0.";
	return elementPath.back();
}

absl::StatusOr<std::shared_ptr<MenuElement>> NavigationCursor::getParentOfCurrentElement() const {
	if (elementPath.empty()) {
		return absl::NotFoundError("Current element is the root element, which has no parent.");
	}
	std::shared_ptr<MenuElement> currentElement = rootElement;
	for (size_t i = 0; i < elementPath.size() - 1; ++i) {
		int index = elementPath[i];
		if (!currentElement->children.has_value() || index >= currentElement->children->size()) {
			return absl::NotFoundError("Invalid path: index path out of bounds at index " + std::to_string(index));
		}
		currentElement = (*currentElement->children)[index];
	}
	return currentElement;
}

absl::Status NavigationCursor::moveNext() {
	auto currentElementOrStatus = getCurrentElement();
	if (!currentElementOrStatus.ok())
		return currentElementOrStatus.status();
	std::shared_ptr<MenuElement> currentElement = currentElementOrStatus.value();
	auto parentElement = getParentOfCurrentElement();
	if(!parentElement.ok())
		return parentElement.status();
	std::shared_ptr<MenuElement> parentElementValue = parentElement.value();	
}
