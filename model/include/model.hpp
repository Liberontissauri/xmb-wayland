#include "absl/status/statusor.h"
#include <absl/status/status.h>
#include <absl/types/optional.h>
#include <memory>

// Forward declaration so that MenuAction can reference MenuElement without circular dependency
struct MenuElement;

using MenuAction = std::function<void(MenuElement& element)>;

struct MenuElement {
	int id;
	absl::optional<std::string> name;
	absl::optional<std::string> icon;
	absl::optional<std::weak_ptr<MenuElement>> parent;
	absl::optional<std::vector<std::shared_ptr<MenuElement>>> children;
	absl::optional<MenuAction> action;
};

using PathToElement = std::vector<int>;

class XMBTree {
	public:
		std::shared_ptr<MenuElement> rootElement;
		XMBTree(std::shared_ptr<MenuElement> rootElement);

		/// @brief Places the given element at the specified path. If there is already an element at that path, it will be replaced and returned.
		/// If the path is invalid (e.g. trying to place an element in a non-existent parent), an error status will be returned.
		absl::StatusOr<std::shared_ptr<MenuElement>> placeElementInPath(PathToElement path, std::shared_ptr<MenuElement> elementToInsert);
		/// @brief Retrieves the element at the specified path. If the path is invalid, an error status will be returned.
		absl::StatusOr<std::shared_ptr<MenuElement>> getElementAtPath(PathToElement path) const;
		/// @brief Retrieves the parent of the element at the specified path. If the path is invalid or if the element at
		///  that path is the root (which has no parent), an error status will be returned.
		absl::StatusOr<std::shared_ptr<MenuElement>> getChildrenOfElementAtPath(PathToElement path) const;
};

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

struct XMBModel {
	std::shared_ptr<MenuElement> rootElement;
	std::shared_ptr<NavigationCursor> navigationCursor;
};
