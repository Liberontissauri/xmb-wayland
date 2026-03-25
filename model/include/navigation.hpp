#include <memory>

#include "tree.hpp"

class NavigationCursor {
	std::shared_ptr<XMBTree> tree;
	PathToElement elementPath;
	public:
		NavigationCursor(std::shared_ptr<XMBTree> tree);

		absl::StatusOr<std::shared_ptr<MenuElement>> getCurrentElement() const;

		int getCurrentMenuIndex() const;

		absl::Status moveNext();
		absl::Status movePrevious();
		absl::Status moveInto(int innerIndex);
		absl::Status moveOut();
};
