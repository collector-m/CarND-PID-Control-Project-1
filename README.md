# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## PID

Using the equations Sebastian gave in his lecture, I've managed to
create a PID controller to control the speed and direction of the car.

## Koefficients

### Steering PID

My initial hypothesis was the proportionality is not as important
as the rate of change for a CTE. If the CTE starts to change very
suddenly the correct response is to start changing with the
acceleration of the CTE. This is like if you notice the right side
of the road start to creep up you need to start correction.

My initial guess for porotionality of the steering control ended up being
1/7th as important as the D component

### Throttle PID

Throttling is much different, however. The ideal throttle response rolls on
hard and lets off quick. Think high performance vehicles. They rev quickly and will rev down as equally as fast.

I started off with the guess that proportionality was many orders of magnitude more important. It ended up being around 10x importance. I also noticed that the car would accelerate in corners and slow down in straight
aways! By the time the car got to the last big cure it would spin out.

To fix this I changed the integral component to remember a very small amount
of the CTE with the hopes that this would slow the car down by the end of the course. Possibly reset the Components after a while to keep them from
growing too large.

I also had the final throttle value subtracted from a constant. Initially it
was 1 but found that I had to turn it down to .25 to keep the car from
going too fast.

## Building & Installing
### Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

### Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`.

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)
