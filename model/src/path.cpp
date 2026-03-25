#include "path.hpp"

absl::StatusOr<PathToElement> getParentPath(PathToElement path) {
	if (path.empty()) {
		return absl::InvalidArgumentError("Cannot get parent path of an empty path (root element).");
	}
	PathToElement parentPath = path;
	parentPath.pop_back();
	return parentPath;
};

absl::StatusOr<PathToElement> getChildPath(PathToElement path, int childIndex) {
	if (childIndex < 0) {
		return absl::InvalidArgumentError("Child index cannot be negative.");
	}
	PathToElement childPath = path;
	childPath.push_back(childIndex);
	return childPath;
};

absl::StatusOr<PathToElement> getSiblingPath(PathToElement path, int siblingIndex) {
	if (siblingIndex < 0) {
		return absl::InvalidArgumentError("Sibling index cannot be negative.");
	}
	PathToElement siblingPath = path;
	siblingPath.back() = siblingIndex;
	return siblingPath;
};
