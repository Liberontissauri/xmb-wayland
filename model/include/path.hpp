#include "absl/status/statusor.h"
#include <vector>

using PathToElement = std::vector<int>;

/// Returns the path to the parent of the given path. If the given path is empty (i.e. it points to the root element), an error status will be returned.
/// [0, 3, 5] would return [0, 3]
absl::StatusOr<PathToElement> getParentPath(PathToElement path);

/// Returns the path to the child at the specified index of the given path. If the given path is empty or the index is invalid, an error status will be returned.
/// [0, 3] with index 2 would return [0, 3, 2]
absl::StatusOr<PathToElement> getChildPath(PathToElement path, int childIndex);

/// Returns the path to the sibling at the specified index of the given path. If the given path is empty or the index is invalid, an error status will be returned.
/// [0, 3, 5] with index 2 would return [0, 3, 2]
absl::StatusOr<PathToElement> getSiblingPath(PathToElement path, int siblingIndex);