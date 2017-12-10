void setup() {
  size(480, 270);
  background(255);
}

void draw() {
  stroke(0);

  // Draw a line from previous mouse location to current mouse location.
  line(pmouseX, pmouseY, mouseX, mouseY);
}