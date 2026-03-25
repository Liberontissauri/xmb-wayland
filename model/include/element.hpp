// Forward declaration so that MenuAction can reference MenuElement without circular dependency
#include "absl/types/optional.h"
#include <memory>

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