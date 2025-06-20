public class HouseBuilder implements IHouseBuilder {
    String color;
    int floors;
    int rooms;
    String owner;
    String address;
    public IHouseBuilder withColor(String c) {
        this.color = c;
        return this;
    }
    public IHouseBuilder withFloors(int floors) {
        this.floors = floors;
        return this;
    }
    public IHouseBuilder withRooms(int rooms) {
        this.rooms = rooms;
        return this;
    }
    public IHouseBuilder withOwner(String owner) {
        this.owner = owner;
        return this;
    }
    public IHouseBuilder withAddress(String address) {
        this.address = address;
        return this;
    }
    @Override
    public House build() {
        return new House(color, floors, rooms, owner, address);
    }

}
