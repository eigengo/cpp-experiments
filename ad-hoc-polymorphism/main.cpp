/*
 * C++ Experiments: Ad-hoc polymorphism Copyright (C) 2016 Eigengo
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "drawable"
#include "history"

// As a demo, it is possible to add an element of arbitrary type...
class entry_t {

};

// ... as long as there is an implementation of ``draw`` for that type
template <>
void draw(const entry_t&, std::ostream& out, size_t position) {
    out << std::string(position, ' ') << "entry_t" << std::endl;
}

int main() {
    history_t h(1);

    current(h).emplace_back(0);
    current(h).emplace_back(std::string("Hello"));

    draw(current(h), std::cout, 0);
    std::cout << std::string(50, '-') << std::endl;

    commit(h);

    current(h).emplace_back(current(h));
    current(h).emplace_back(entry_t());
    current(h)[1] = std::string("World");

    draw(current(h), std::cout, 0);
    std::cout << std::string(50, '-') << std::endl;

    undo(h);

    draw(current(h), std::cout, 0);
    std::cout << std::string(50, '-') << std::endl;

    return 0;
}
