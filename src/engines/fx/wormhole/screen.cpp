#include "screen.hpp"

#include "core/ui/vector_graphics.hpp"

namespace otto::engines::wormhole {

  using namespace core::ui;
  using namespace core::ui::vg;

  void Screen::action(itc::prop_change<&Props::filter>, float f) noexcept
  {
    filter_ = f;
  }
  void Screen::action(itc::prop_change<&Props::shimmer>, float s) noexcept
  {
    shimmer_ = s;
  }
  void Screen::action(itc::prop_change<&Props::length>, float l) noexcept
  {
    length_ = l;
  }
  void Screen::action(itc::prop_change<&Props::damping>, float d) noexcept
  {
    damping_ = d;
  }

  void Screen::draw(ui::vg::Canvas& ctx)
  {
    using namespace ui::vg;

    // declaration of star radius of first group of stars
    float starradius = 3;
    Vec2 direction = Vec2{3, -2} * (length_ * 3 + 0.6);
    float minscale = 0.55;
    float frontscale = std::min(1.f, (minscale + damping_ * (1 - minscale) * 2));
    float backscale = std::min(1.f, (minscale + (1 - damping_) * (1 - minscale) * 2));

    // 1st group of stars.
    ctx.group([&] {
      ctx.beginPath();
      ctx.circle({126.6, 75.2}, starradius);
      ctx.fillStyle(Colors::Yellow.dim(1 - shimmer_));
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({228.8, 162.3}, starradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({186.8, 81.3}, starradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({259.0, 28.3}, starradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({207.6, 192.4}, starradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({154.8, 93.3}, starradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({144.3, 26.3}, starradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({257.8, 193.0}, starradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({223.5, 128.3}, starradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({294.1, 181.6}, starradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({52.7, 190.3}, starradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({106.6, 42.2}, starradius);
      ctx.fill();
    });

    // declaration of star radius of second group of stars
    float secondstarradius = 2;

    ctx.group([&] {
      // 2nd group of stars.
      ctx.beginPath();
      ctx.circle({255.3, 168.8}, secondstarradius);
      ctx.fillStyle(Colors::Yellow.dim(1 - shimmer_));

      // (stars)
      ctx.beginPath();
      ctx.circle({149.5, 60.6}, secondstarradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({200.6, 164.6}, secondstarradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({77.6, 164.7}, secondstarradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({175.2, 48.8}, secondstarradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({228.0, 147.9}, secondstarradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({228.6, 206.1}, secondstarradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({294.0, 106.1}, secondstarradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({159.3, 112.0}, secondstarradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({289.7, 202.0}, secondstarradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({45.9, 164.4}, secondstarradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({100.4, 212.8}, secondstarradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({100.5, 65.7}, secondstarradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({213.7, 83.2}, secondstarradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({213.0, 91.9}, secondstarradius);
      ctx.fill();
    });

    // 3rd group of stars. for tobias.
    ctx.group([&] {
      ctx.beginPath();
      ctx.circle({273, 68}, starradius);
      ctx.fillStyle(Colors::Yellow.dim(1 - shimmer_));
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({255, 118}, starradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({220, 57}, starradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({200, 87}, starradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({203, 142}, starradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({113, 123}, starradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({106, 176}, starradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({159, 164}, starradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({154, 190}, starradius);
      ctx.fill();

      // (stars)
      ctx.beginPath();
      ctx.circle({182, 185}, starradius);
      ctx.fill();
    });

    // mass value
    ctx.save();
    ctx.font(Fonts::Norm, 40);
    ctx.fillStyle(Colors::Blue);
    ctx.fillText(fmt::format("{}", std::round(filter_ * 100)), 22.9, 76.2);

    // mass text
    ctx.font(Fonts::Norm, 25);
    ctx.fillStyle(Colors::White);
    ctx.fillText("treble", 22.9, 35.4);

    ctx.restore();

    // stars value
    ctx.save();
    ctx.font(Fonts::Norm, 40);
    ctx.fillStyle(Colors::Yellow);
    ctx.fillText(fmt::format("{}", std::round(shimmer_ * 100)), 22.9, 147.9);

    // stars text
    ctx.font(Fonts::Norm, 25);
    ctx.fillStyle(Colors::White);
    ctx.fillText("stars", 22.9, 106.1);

    ctx.restore();


    // Green Dot at the end
    ctx.beginPath();
    ctx.circle({241.1, 85.3}, 3);
    ctx.lineWidth(6.0);
    ctx.strokeStyle(Colors::Green);
    ctx.stroke();

    // WormHole/GreenLine
    ctx.beginPath();
    ctx.moveTo(144.3, 151.2);
    ctx.lineTo(241.1, 85.3);
    ctx.lineWidth(6.0);
    ctx.strokeStyle(Colors::Green);
    ctx.lineCap(LineCap::ROUND);
    ctx.lineJoin(LineJoin::ROUND);
    ctx.stroke();

    // WormHole/BackPad
    ctx.group([&] {
      Point translation = direction * 5;

      ctx.beginPath();
      ctx.translate(translation);
      ctx.lineWidth(6 / backscale);
      ctx.scaleTowards(backscale, {192.714, 118.458});
      ctx.moveTo(226.4, 176.1);
      ctx.lineTo(226.4, 95.0);
      ctx.lineTo(159.0, 60.8);
      ctx.lineTo(159.0, 103.6);
      ctx.bezierCurveTo(159.0, 79.2, 172.3, 68.2, 192.7, 78.2);
      ctx.bezierCurveTo(213.1, 88.2, 226.4, 108.7, 226.4, 135.3);
      ctx.bezierCurveTo(226.4, 161.9, 213.9, 169.8, 192.7, 159.0);
      ctx.lineTo(226.4, 176.1);
      ctx.closePath();
      ctx.fillStyle(Colors::White);
      ctx.fill();
      ctx.strokeStyle(Colors::White);
      ctx.stroke();
    });

    // WormHole/BackOutterRing
    ctx.group([&] {
      Point translation = direction * 4.7;

      ctx.beginPath();
      ctx.translate(translation);
      ctx.lineWidth(6 / backscale);
      ctx.scaleTowards(backscale, {192.714, 118.458});
      ctx.moveTo(170.3, 113.6);
      ctx.bezierCurveTo(170.1, 111.6, 169.9, 109.6, 169.9, 107.6);
      ctx.bezierCurveTo(169.9, 91.1, 178.9, 83.7, 192.7, 90.4);
      ctx.bezierCurveTo(206.5, 97.2, 215.5, 111.1, 215.5, 129.0);
      ctx.bezierCurveTo(215.5, 147.0, 207.0, 152.3, 192.7, 145.1);
      ctx.bezierCurveTo(191.2, 144.3, 189.7, 143.4, 188.3, 142.5);
      ctx.strokeStyle(Colors::Red);
      ctx.stroke();
    });

    // WormHole/InnerRing1
    ctx.group([&] {
      Point translation = direction * -1;

      ctx.beginPath();
      ctx.translate(translation);
      ctx.moveTo(182.3, 113.6);
      ctx.bezierCurveTo(182.3, 106.1, 186.4, 102.7, 192.7, 105.8);
      ctx.bezierCurveTo(199.0, 108.9, 203.1, 115.2, 203.1, 123.5);
      ctx.bezierCurveTo(203.1, 131.7, 199.3, 134.1, 192.7, 130.8);
      ctx.stroke(Colors::Red);
    });

    // WormHole/InnerRing2
    ctx.group([&] {
      Point translation = direction * 1;

      ctx.beginPath();
      ctx.translate(translation);
      ctx.moveTo(182.3, 113.6);
      ctx.bezierCurveTo(182.3, 106.1, 186.4, 102.7, 192.7, 105.8);
      ctx.bezierCurveTo(199.0, 108.9, 203.1, 115.2, 203.1, 123.5);
      ctx.bezierCurveTo(203.1, 131.7, 199.3, 134.1, 192.7, 130.8);
      ctx.stroke(Colors::Red);
    });

    // WormHole/InnerRing3
    ctx.group([&] {
      Point translation = direction * 3.2;

      ctx.beginPath();
      ctx.translate(translation);
      ctx.moveTo(182.3, 113.6);
      ctx.bezierCurveTo(182.3, 106.1, 186.4, 102.7, 192.7, 105.8);
      ctx.bezierCurveTo(199.0, 108.9, 203.1, 115.2, 203.1, 123.5);
      ctx.bezierCurveTo(203.1, 131.7, 199.3, 134.1, 192.7, 130.8);
      ctx.stroke(Colors::Red);
    });

    // WormHole/FrontInnerRing

    ctx.group([&] {
      Point translation = direction * -4.4;

      ctx.beginPath();
      ctx.translate(translation);
      ctx.lineWidth(6 / frontscale);
      ctx.scaleTowards(frontscale, {192.714, 118.458});
      ctx.moveTo(205.4, 124.2);
      ctx.bezierCurveTo(205.4, 134.2, 200.7, 137.2, 192.7, 133.1);
      ctx.bezierCurveTo(184.7, 129.1, 180.0, 121.4, 180.0, 112.2);
      ctx.bezierCurveTo(180.0, 103.0, 185.0, 98.9, 192.7, 102.7);
      ctx.bezierCurveTo(200.4, 106.5, 205.4, 114.2, 205.4, 124.2);
      ctx.closePath();
      ctx.lineCap(LineCap::BUTT);
      ctx.lineJoin(LineJoin::MITER);
      ctx.miterLimit(10.0);
      ctx.stroke(Colors::Red);
    });

    // WormHole/FrontRing
    ctx.group([&] {
      Point translation = direction * -4.8;

      ctx.beginPath();
      ctx.translate(translation);
      ctx.lineWidth(6 / frontscale);
      ctx.scaleTowards(frontscale, {192.714, 118.458});
      ctx.moveTo(215.5, 129.0);
      ctx.bezierCurveTo(215.5, 147.0, 207.0, 152.3, 192.7, 145.1);
      ctx.bezierCurveTo(178.4, 137.8, 169.9, 124.1, 169.9, 107.6);
      ctx.bezierCurveTo(169.9, 91.1, 178.9, 83.7, 192.7, 90.4);
      ctx.bezierCurveTo(206.5, 97.2, 215.5, 111.1, 215.5, 129.0);
      ctx.closePath();
      ctx.stroke(Colors::Red);
    });

    // WormHole/FrontPadGroup/FrontPad3
    ctx.group([&] {
      Point translation = direction * -5;

      ctx.beginPath();
      ctx.translate(translation);
      ctx.lineWidth(6 / frontscale);
      ctx.scaleTowards(frontscale, {192.714, 118.458});
      ctx.moveTo(192.7, 158.6);
      ctx.lineTo(226.4, 175.7);
      ctx.lineTo(226.4, 134.9);
      ctx.bezierCurveTo(226.4, 161.5, 213.9, 169.4, 192.7, 158.6);
      ctx.closePath();
      ctx.fill();
      ctx.strokeStyle(Color::bytes(250, 249, 249));
      ctx.lineCap(LineCap::ROUND);
      ctx.lineJoin(LineJoin::ROUND);
      ctx.stroke();

      // WormHole/FrontPadGroup/FrontPad2
      ctx.beginPath();
      ctx.moveTo(159.0, 60.4);
      ctx.lineTo(159.0, 103.2);
      ctx.bezierCurveTo(159.0, 78.8, 172.3, 67.8, 192.7, 77.8);
      ctx.bezierCurveTo(213.1, 87.9, 226.4, 108.3, 226.4, 134.9);
      ctx.lineTo(226.4, 94.6);
      ctx.lineTo(159.0, 60.4);
      ctx.closePath();
      ctx.fill();
      ctx.stroke();

      // WormHole/FrontPadGroup/FrontPad1
      ctx.beginPath();
      ctx.moveTo(192.7, 158.6);
      ctx.bezierCurveTo(171.5, 147.9, 159.0, 127.6, 159.0, 103.2);
      ctx.lineTo(159.0, 141.6);
      ctx.lineTo(192.7, 158.6);
      ctx.closePath();
      ctx.fill();
      ctx.stroke();
    });


    // WormHole/GreenLineCheat
    ctx.group([&] {
      Point fixed = {144.3, 151.2};
      Point translation = Vec2(177.828 + 12, 128.387 - 8) + direction * -4.4;

      if (translation.x > fixed.x) {
        ctx.beginPath();
        ctx.moveTo(144.3, 151.2);
        ctx.lineTo(translation);
        ctx.lineWidth(6.0);
        ctx.strokeStyle(Colors::Green);
        ctx.lineCap(LineCap::ROUND);
        ctx.lineJoin(LineJoin::ROUND);
        ctx.stroke();
      }
    });

    // Green Dot
    ctx.beginPath();
    ctx.circle({144.3, 151.2}, 3);
    ctx.lineWidth(6.0);
    ctx.strokeStyle(Colors::Green);
    ctx.stroke();
  }

} // namespace otto::engines::wormhole
