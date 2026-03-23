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

class NavigationCursor {
	std::shared_ptr<MenuElement> rootElement;
	PathToElement elementPath;
	public:
		NavigationCursor(std::shared_ptr<MenuElement> element);
		absl::StatusOr<std::shared_ptr<MenuElement>> getCurrentElement() const;
		absl::StatusOr<std::shared_ptr<MenuElement>> getParentOfCurrentElement() const;
		absl::StatusOr<std::shared_ptr<MenuElement>> getElementAtPath(PathToElement path) const;
		absl::StatusOr<std::shared_ptr<MenuElement>> getCurrentElementPath() const;
		absl::StatusOr<std::vector<std::shared_ptr<MenuElement>>> getCurrentElementChildren() const;
		int getCurrentMenuIndex() const;

		absl::StatusOr<std::shared_ptr<MenuElement>> insertElementIntoElementPath(PathToElement path, std::shared_ptr<MenuElement> element, int insertIndex);
		absl::StatusOr<std::shared_ptr<MenuElement>> insertElementIntoCurrentElement(std::shared_ptr<MenuElement> element, int insertIndex);

		absl::Status moveNext();
		absl::Status movePrevious();
		absl::Status moveInto(int moveIntoIndex);
		absl::Status moveOut();
};

struct XMBModel {
	std::shared_ptr<MenuElement> rootElement;
	std::shared_ptr<NavigationCursor> navigationCursor;
};
