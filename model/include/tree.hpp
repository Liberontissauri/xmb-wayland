#include "absl/status/statusor.h"
#include <memory>

#include "path.hpp"
#include "element.hpp"

class XMBTree {
	public:
		std::shared_ptr<MenuElement> rootElement;
		XMBTree(std::shared_ptr<MenuElement> rootElement);

		/// Places the given element at the specified path. If there is already an element at that path, it will be replaced and returned.
		/// If the path is invalid (e.g. trying to place an element in a non-existent parent), an error status will be returned.
		absl::StatusOr<std::shared_ptr<MenuElement>> placeElementInPath(PathToElement path, std::shared_ptr<MenuElement> elementToInsert);
		/// Retrieves the element at the specified path. If the path is invalid, an error status will be returned.
		absl::StatusOr<std::shared_ptr<MenuElement>> getElementAtPath(PathToElement path) const;
};
