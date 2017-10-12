# Midterm IoT Project

Name:  PATRICIA TORVALDS pmt / pmt15

Date: 10.11.17

## Project: TRASH CLOUDS

### Conceptual Description

My project in conjunction with @tracylooloo engages in the ideas of e-waste. While Tracy Lu's project is a trash can, mine represents the physical fallout of electronic waste in the form of a "toxic cloud"/"trash cloud" actually made of 3D printer scraps. The trash cloud is filled with red and yellow LED lights which turn on when either someone presses the button on my piece, or when someone removes the lid of Tracy's trash can. Often, software users end their interactions with so-called trash at the end of an electronic's lifespan; my piece extends that lifespan and makes trash visible.
### Form

My piece is, importantly, largely mad from "trash." The orange smokestack supporting the toxic cloud was found abandoned in the CoLab. The trash cloud itself is made of 3D printed refuse. While this piece may look strange in its final form, the materials used to produce it are part of the message. The industrial looking plastic box is reminiscent of both a factory setting and factory-produced goods, while the bright oranges, reds, and yellows lend an unnatural glow to the piece even when the LEDs are off.

**Finished Enclosure:**

![Finished Enclosure](IMG_20171011_234407.jpg)

**Electronics Exposed:**

![Enclosure with electronics exposed](IMG_20171011_233514.jpg)
![Enclosure with electronics exposed2](IMG_20171011_233459.jpg)


### Technical Details
My project works directly with Tracy Lu's in order to deliver its full message. It uses two push buttons and three LEDs to accomplish this. While the hardware seems minimalistic, it is neatly packaged in that all the LEDs are connected but each button serves a unique purpose. One button, symbolic of the labor used to clean up e-waste, lights the toxic cloud. The other button sends a message back to Tracy's device, symbolic of how while e-waste may feel like it has negligible impact it is actually inescapable.
The code itself uses Particle.publish and Particle.subscribe to send and receive messages, then executes them in the cloudOn function.
```
  if (buttonState == HIGH) {
    Particle.publish("patricia_tracy_pmt15_tl177", "rainbow"); // replace with your team's name and choose a color for your button
    delay(2000);
  }
```
...

```
void cloudOn(const char *event, const char *data){
    thing = data;
    if (thing == "cloud"){
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW); }
    else{digitalWrite(ledPin, LOW); }
}
```

but also link to your project's full code in this repository:  [pmt_midterm.ino](pmt_midterm.ino)

**Wiring Diagram**

![Wiring Diagram](WiringDiagram.png)
