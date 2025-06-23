public class ShapeFactory {
    public Shape createShape(String shapeType) throws Exception {
        // Jika shapeType adalah null lempar exception dengan pesan "Shape type cannot be null"
        // Jika shapeType tidak sesuai dengan "CIRCLE", "RECTANGLE", atau "TRIANGLE" lempar exception dengan pesan "Unknown shape type: {shapeType}"
        
        // Sesuai dengan petunjuk, kita akan membuat factory method untuk membuat objek Shape berdasarkan tipe yang diberikan.
        if (shapeType == null) {
            throw new Exception("Shape type cannot be null");
        }

        if (shapeType == "CIRCLE") {
            return new Circle();
        } else if (shapeType == "RECTANGLE") {
            return new Rectangle();
        } else if (shapeType == "TRIANGLE") {
            return new Triangle();
        } else {
            throw new Exception("Unknown shape type: " + shapeType);
        }
    }
}