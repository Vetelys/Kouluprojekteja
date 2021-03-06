#ifndef IOBJECTMANAGER_H
#define IOBJECTMANAGER_H

#include <memory>
#include <vector>


namespace Course {

class TileBase;
class Coordinate;

#ifndef COURSE_OBJECTID
#define COURSE_OBJECTID
using ObjectId = unsigned int;
#endif

/**
 * @brief The iObjectManager class is an interface which the Course-side
 * code uses to interact with the ObjectManager implemented by the students.
 *
 * @note The interface declares only functions required by the Course-side code.
 * The actual implementation can (and should!) contain more stuff.
 */
class iObjectManager
{
public:
    /**
     * @brief Default destructor.
     */
    virtual ~iObjectManager() = default;

    /**
     * @brief Adds new tiles to the ObjectManager.
     * @param tiles contains the tiles to be added.
     */
    virtual void addTiles(
            const std::vector<std::shared_ptr<TileBase>>& tiles) = 0;

    /**
     * @brief Returns a pointer to a Tile that has specified coordinate.
     * @param coordinate
     * @return
     * @post Exception Guarantee: Basic
     */
    virtual std::shared_ptr<TileBase> getTile(
            const Coordinate& coordinate) = 0;

    /**
     * @brief Returns a pointer to a Tile that has specified ID
     * @param id
     * @return
     * @post Exception Guarantee: Basic
     */
    virtual std::shared_ptr<TileBase> getTile(const ObjectId& id) = 0;

    /**
     * @brief Returns a vector of pointers to Tiles specified by Coordinates.
     * @param coordinates
     * @return
     * @post Exception Guarantee: Basic
     */
    virtual std::vector<std::shared_ptr<TileBase>> getTiles(
            const std::vector<Coordinate>& coordinates) = 0;


}; // class iObjectManager

} // namespace Course


#endif // IOBJECTMANAGER_H
