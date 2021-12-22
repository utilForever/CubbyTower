// Copyright (c) 2021 CubbyTower Team
// Chris Ohk, Minkyu Lee, Minjune Yi
// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CUBBYTOWER_DATA_HPP
#define CUBBYTOWER_DATA_HPP

namespace CubbyTower
{
static const float MAP_VERTS[] = {
    6.0f,      2.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      7.0f,
    2.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      6.0f,      2.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      6.0f,      3.0f,      0.356863f,
    0.431373f, 0.882353f, 1.0f,      7.0f,      2.0f,      0.356863f, 0.431373f,
    0.882353f, 1.0f,      8.0f,      2.0f,      0.356863f, 0.431373f, 0.882353f,
    1.0f,      7.0f,      3.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,
    8.0f,      3.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      8.0f,
    2.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      9.0f,      2.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      8.0f,      3.0f,      0.356863f,
    0.431373f, 0.882353f, 1.0f,      9.0f,      3.0f,      0.356863f, 0.431373f,
    0.882353f, 1.0f,      9.0f,      2.0f,      0.356863f, 0.431373f, 0.882353f,
    1.0f,      10.0f,     2.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,
    9.0f,      3.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      10.0f,
    3.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      10.0f,     2.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      11.0f,     2.0f,      0.356863f,
    0.431373f, 0.882353f, 1.0f,      10.0f,     3.0f,      0.356863f, 0.431373f,
    0.882353f, 1.0f,      11.0f,     3.0f,      0.356863f, 0.431373f, 0.882353f,
    1.0f,      11.0f,     2.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,
    12.0f,     2.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      11.0f,
    3.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      12.0f,     3.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      12.0f,     2.0f,      0.356863f,
    0.431373f, 0.882353f, 1.0f,      13.0f,     2.0f,      0.356863f, 0.431373f,
    0.882353f, 1.0f,      13.0f,     2.0f,      0.356863f, 0.431373f, 0.882353f,
    1.0f,      13.0f,     3.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,
    6.0f,      3.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      6.0f,
    4.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      7.0f,      3.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      7.0f,      4.0f,      0.356863f,
    0.431373f, 0.882353f, 1.0f,      12.0f,     3.0f,      0.356863f, 0.431373f,
    0.882353f, 1.0f,      12.0f,     4.0f,      0.356863f, 0.431373f, 0.882353f,
    1.0f,      13.0f,     3.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,
    13.0f,     4.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      0.0f,
    4.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      1.0f,      4.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      0.0f,      5.0f,      0.356863f,
    0.431373f, 0.882353f, 1.0f,      1.0f,      5.0f,      0.356863f, 0.431373f,
    0.882353f, 1.0f,      1.0f,      4.0f,      0.356863f, 0.431373f, 0.882353f,
    1.0f,      2.0f,      4.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,
    1.0f,      5.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      2.0f,
    5.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      2.0f,      4.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      3.0f,      4.0f,      0.356863f,
    0.431373f, 0.882353f, 1.0f,      2.0f,      5.0f,      0.356863f, 0.431373f,
    0.882353f, 1.0f,      3.0f,      5.0f,      0.356863f, 0.431373f, 0.882353f,
    1.0f,      3.0f,      4.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,
    4.0f,      4.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      4.0f,
    4.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      4.0f,      5.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      6.0f,      5.0f,      0.356863f,
    0.431373f, 0.882353f, 1.0f,      7.0f,      5.0f,      0.356863f, 0.431373f,
    0.882353f, 1.0f,      6.0f,      4.0f,      0.356863f, 0.431373f, 0.882353f,
    1.0f,      6.0f,      5.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,
    7.0f,      4.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      8.0f,
    4.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      7.0f,      5.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      8.0f,      5.0f,      0.356863f,
    0.431373f, 0.882353f, 1.0f,      8.0f,      4.0f,      0.356863f, 0.431373f,
    0.882353f, 1.0f,      9.0f,      4.0f,      0.356863f, 0.431373f, 0.882353f,
    1.0f,      9.0f,      4.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,
    9.0f,      5.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      12.0f,
    4.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      12.0f,     5.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      13.0f,     4.0f,      0.356863f,
    0.431373f, 0.882353f, 1.0f,      13.0f,     5.0f,      0.356863f, 0.431373f,
    0.882353f, 1.0f,      3.0f,      5.0f,      0.356863f, 0.431373f, 0.882353f,
    1.0f,      3.0f,      6.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,
    4.0f,      5.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      4.0f,
    6.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      8.0f,      5.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      8.0f,      6.0f,      0.356863f,
    0.431373f, 0.882353f, 1.0f,      9.0f,      5.0f,      0.356863f, 0.431373f,
    0.882353f, 1.0f,      9.0f,      6.0f,      0.356863f, 0.431373f, 0.882353f,
    1.0f,      12.0f,     5.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,
    12.0f,     6.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      13.0f,
    5.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      13.0f,     6.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      3.0f,      6.0f,      0.356863f,
    0.431373f, 0.882353f, 1.0f,      3.0f,      7.0f,      0.356863f, 0.431373f,
    0.882353f, 1.0f,      4.0f,      6.0f,      0.356863f, 0.431373f, 0.882353f,
    1.0f,      4.0f,      7.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,
    8.0f,      6.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      8.0f,
    7.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      9.0f,      6.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      9.0f,      7.0f,      0.356863f,
    0.431373f, 0.882353f, 1.0f,      12.0f,     7.0f,      0.356863f, 0.431373f,
    0.882353f, 1.0f,      13.0f,     7.0f,      0.356863f, 0.431373f, 0.882353f,
    1.0f,      12.0f,     6.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,
    12.0f,     7.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      13.0f,
    6.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      14.0f,     6.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      13.0f,     7.0f,      0.356863f,
    0.431373f, 0.882353f, 1.0f,      14.0f,     7.0f,      0.356863f, 0.431373f,
    0.882353f, 1.0f,      14.0f,     6.0f,      0.356863f, 0.431373f, 0.882353f,
    1.0f,      15.0f,     6.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,
    14.0f,     7.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      15.0f,
    7.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      15.0f,     6.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      16.0f,     6.0f,      0.356863f,
    0.431373f, 0.882353f, 1.0f,      15.0f,     7.0f,      0.356863f, 0.431373f,
    0.882353f, 1.0f,      16.0f,     7.0f,      0.356863f, 0.431373f, 0.882353f,
    1.0f,      3.0f,      8.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,
    4.0f,      8.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      3.0f,
    7.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      3.0f,      8.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      4.0f,      7.0f,      0.356863f,
    0.431373f, 0.882353f, 1.0f,      5.0f,      7.0f,      0.356863f, 0.431373f,
    0.882353f, 1.0f,      4.0f,      8.0f,      0.356863f, 0.431373f, 0.882353f,
    1.0f,      5.0f,      8.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,
    5.0f,      7.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      6.0f,
    7.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      6.0f,      7.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      6.0f,      8.0f,      0.356863f,
    0.431373f, 0.882353f, 1.0f,      8.0f,      7.0f,      0.356863f, 0.431373f,
    0.882353f, 1.0f,      8.0f,      8.0f,      0.356863f, 0.431373f, 0.882353f,
    1.0f,      9.0f,      7.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,
    9.0f,      8.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      5.0f,
    8.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      5.0f,      9.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      6.0f,      8.0f,      0.356863f,
    0.431373f, 0.882353f, 1.0f,      6.0f,      9.0f,      0.356863f, 0.431373f,
    0.882353f, 1.0f,      8.0f,      8.0f,      0.356863f, 0.431373f, 0.882353f,
    1.0f,      8.0f,      9.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,
    9.0f,      8.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      9.0f,
    9.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      5.0f,      9.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      5.0f,      10.0f,     0.356863f,
    0.431373f, 0.882353f, 1.0f,      6.0f,      9.0f,      0.356863f, 0.431373f,
    0.882353f, 1.0f,      6.0f,      10.0f,     0.356863f, 0.431373f, 0.882353f,
    1.0f,      8.0f,      9.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,
    8.0f,      10.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,      9.0f,
    9.0f,      0.356863f, 0.431373f, 0.882353f, 1.0f,      9.0f,      10.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      5.0f,      10.0f,     0.356863f,
    0.431373f, 0.882353f, 1.0f,      5.0f,      11.0f,     0.356863f, 0.431373f,
    0.882353f, 1.0f,      6.0f,      10.0f,     0.356863f, 0.431373f, 0.882353f,
    1.0f,      6.0f,      11.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,
    8.0f,      11.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,      9.0f,
    11.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,      8.0f,      10.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      8.0f,      11.0f,     0.356863f,
    0.431373f, 0.882353f, 1.0f,      9.0f,      10.0f,     0.356863f, 0.431373f,
    0.882353f, 1.0f,      10.0f,     10.0f,     0.356863f, 0.431373f, 0.882353f,
    1.0f,      9.0f,      11.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,
    10.0f,     11.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,      10.0f,
    10.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,      11.0f,     10.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      10.0f,     11.0f,     0.356863f,
    0.431373f, 0.882353f, 1.0f,      11.0f,     11.0f,     0.356863f, 0.431373f,
    0.882353f, 1.0f,      11.0f,     10.0f,     0.356863f, 0.431373f, 0.882353f,
    1.0f,      12.0f,     10.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,
    12.0f,     10.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,      12.0f,
    11.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,      5.0f,      11.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      5.0f,      12.0f,     0.356863f,
    0.431373f, 0.882353f, 1.0f,      6.0f,      11.0f,     0.356863f, 0.431373f,
    0.882353f, 1.0f,      6.0f,      12.0f,     0.356863f, 0.431373f, 0.882353f,
    1.0f,      11.0f,     11.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,
    11.0f,     12.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,      12.0f,
    11.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,      12.0f,     12.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      5.0f,      12.0f,     0.356863f,
    0.431373f, 0.882353f, 1.0f,      5.0f,      13.0f,     0.356863f, 0.431373f,
    0.882353f, 1.0f,      6.0f,      12.0f,     0.356863f, 0.431373f, 0.882353f,
    1.0f,      6.0f,      13.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,
    11.0f,     12.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,      11.0f,
    13.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,      12.0f,     12.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      12.0f,     13.0f,     0.356863f,
    0.431373f, 0.882353f, 1.0f,      5.0f,      14.0f,     0.356863f, 0.431373f,
    0.882353f, 1.0f,      6.0f,      14.0f,     0.356863f, 0.431373f, 0.882353f,
    1.0f,      5.0f,      13.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,
    5.0f,      14.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,      6.0f,
    13.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,      7.0f,      13.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      6.0f,      14.0f,     0.356863f,
    0.431373f, 0.882353f, 1.0f,      7.0f,      14.0f,     0.356863f, 0.431373f,
    0.882353f, 1.0f,      7.0f,      13.0f,     0.356863f, 0.431373f, 0.882353f,
    1.0f,      8.0f,      13.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,
    7.0f,      14.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,      8.0f,
    14.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,      8.0f,      13.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      9.0f,      13.0f,     0.356863f,
    0.431373f, 0.882353f, 1.0f,      8.0f,      14.0f,     0.356863f, 0.431373f,
    0.882353f, 1.0f,      9.0f,      14.0f,     0.356863f, 0.431373f, 0.882353f,
    1.0f,      9.0f,      13.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,
    10.0f,     13.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,      9.0f,
    14.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,      10.0f,     14.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      10.0f,     13.0f,     0.356863f,
    0.431373f, 0.882353f, 1.0f,      11.0f,     13.0f,     0.356863f, 0.431373f,
    0.882353f, 1.0f,      10.0f,     14.0f,     0.356863f, 0.431373f, 0.882353f,
    1.0f,      11.0f,     14.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,
    11.0f,     14.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,      12.0f,
    14.0f,     0.356863f, 0.431373f, 0.882353f, 1.0f,      12.0f,     13.0f,
    0.356863f, 0.431373f, 0.882353f, 1.0f,      12.0f,     14.0f,     0.356863f,
    0.431373f, 0.882353f, 1.0f,      0.0f,      4.2f,      0.874510f, 0.443137f,
    0.149020f, 1.0f,      0.0f,      4.8f,      0.874510f, 0.443137f, 0.149020f,
    1.0f,      0.0f,      4.8f,      0.874510f, 0.443137f, 0.149020f, 1.0f,
    0.3f,      4.5f,      0.874510f, 0.443137f, 0.149020f, 1.0f,      0.3f,
    4.5f,      0.874510f, 0.443137f, 0.149020f, 1.0f,      0.0f,      4.2f,
    0.874510f, 0.443137f, 0.149020f, 1.0f,      15.7f,     6.2f,      0.372549f,
    0.803922f, 0.894118f, 1.0f,      15.7f,     6.8f,      0.372549f, 0.803922f,
    0.894118f, 1.0f,      15.7f,     6.8f,      0.372549f, 0.803922f, 0.894118f,
    1.0f,      16.0f,     6.5f,      0.372549f, 0.803922f, 0.894118f, 1.0f,
    16.0f,     6.5f,      0.372549f, 0.803922f, 0.894118f, 1.0f,      15.7f,
    6.2f,      0.372549f, 0.803922f, 0.894118f, 1.0f,
};
}  // namespace CubbyTower

#endif  // CUBBYTOWER_CONSTANTS_HPP