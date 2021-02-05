#include <cassert>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::string simplifyPath(const std::string &path) {
    std::stringstream ss(path);
    std::string tmp;
    std::vector<std::string> v;
    int pos = 0;
    while (std::getline(ss, tmp, '/')) {
        if (tmp == "..") {
            pos = std::max(0, pos - 1);
        } else if (tmp == "." || tmp.empty()) {
            // do nothing
        } else {
            if (pos >= v.size()) {
                v.push_back(tmp);
                ++pos;
            } else {
                v[pos++] = tmp;
            }
        }
    }

    if (pos == 0) {
        return "/";
    }

    std::string ret;
    for (int i = 0; i < pos; ++i) {
        ret += "/" + v[i];
    }

    return ret;
}

int main() {
    assert(simplifyPath("/home/") == "/home");
    assert(simplifyPath("/../") == "/");
    assert(simplifyPath("/home//foo/") == "/home/foo");
    assert(simplifyPath("/a/./b/../../c/") == "/c");
    assert(simplifyPath("/a//b////c/d//././/..") == "/a/b/c");
    return 0;
}
