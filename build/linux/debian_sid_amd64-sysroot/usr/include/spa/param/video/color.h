/* Simple Plugin API
 * Copyright (C) 2016 Wim Taymans <wim.taymans@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __SPA_VIDEO_COLOR_H__
#define __SPA_VIDEO_COLOR_H__

#ifdef __cplusplus
extern "C" {
#endif

/**
 * spa_video_color_range:
 * @SPA_VIDEO_COLOR_RANGE_UNKNOWN: unknown range
 * @SPA_VIDEO_COLOR_RANGE_0_255: [0..255] for 8 bit components
 * @SPA_VIDEO_COLOR_RANGE_16_235: [16..235] for 8 bit components. Chroma has
 *                 [16..240] range.
 *
 * Possible color range values. These constants are defined for 8 bit color
 * values and can be scaled for other bit depths.
 */
enum spa_video_color_range {
	SPA_VIDEO_COLOR_RANGE_UNKNOWN = 0,
	SPA_VIDEO_COLOR_RANGE_0_255,
	SPA_VIDEO_COLOR_RANGE_16_235
};

/**
 * spa_video_color_matrix:
 * @SPA_VIDEO_COLOR_MATRIX_UNKNOWN: unknown matrix
 * @SPA_VIDEO_COLOR_MATRIX_RGB: identity matrix
 * @SPA_VIDEO_COLOR_MATRIX_FCC: FCC color matrix
 * @SPA_VIDEO_COLOR_MATRIX_BT709: ITU-R BT.709 color matrix
 * @SPA_VIDEO_COLOR_MATRIX_BT601: ITU-R BT.601 color matrix
 * @SPA_VIDEO_COLOR_MATRIX_SMPTE240M: SMPTE 240M color matrix
 * @SPA_VIDEO_COLOR_MATRIX_BT2020: ITU-R BT.2020 color matrix. Since: 1.6.
 *
 * The color matrix is used to convert between Y'PbPr and
 * non-linear RGB (R'G'B')
 */
enum spa_video_color_matrix {
	SPA_VIDEO_COLOR_MATRIX_UNKNOWN = 0,
	SPA_VIDEO_COLOR_MATRIX_RGB,
	SPA_VIDEO_COLOR_MATRIX_FCC,
	SPA_VIDEO_COLOR_MATRIX_BT709,
	SPA_VIDEO_COLOR_MATRIX_BT601,
	SPA_VIDEO_COLOR_MATRIX_SMPTE240M,
	SPA_VIDEO_COLOR_MATRIX_BT2020
};

/**
 * spa_video_transfer_function:
 * @SPA_VIDEO_TRANSFER_UNKNOWN: unknown transfer function
 * @SPA_VIDEO_TRANSFER_GAMMA10: linear RGB, gamma 1.0 curve
 * @SPA_VIDEO_TRANSFER_GAMMA18: Gamma 1.8 curve
 * @SPA_VIDEO_TRANSFER_GAMMA20: Gamma 2.0 curve
 * @SPA_VIDEO_TRANSFER_GAMMA22: Gamma 2.2 curve
 * @SPA_VIDEO_TRANSFER_BT709: Gamma 2.2 curve with a linear segment in the lower
 *                           range
 * @SPA_VIDEO_TRANSFER_SMPTE240M: Gamma 2.2 curve with a linear segment in the
 *                               lower range
 * @SPA_VIDEO_TRANSFER_SRGB: Gamma 2.4 curve with a linear segment in the lower
 *                          range
 * @SPA_VIDEO_TRANSFER_GAMMA28: Gamma 2.8 curve
 * @SPA_VIDEO_TRANSFER_LOG100: Logarithmic transfer characteristic
 *                             100:1 range
 * @SPA_VIDEO_TRANSFER_LOG316: Logarithmic transfer characteristic
 *                             316.22777:1 range
 * @SPA_VIDEO_TRANSFER_BT2020_12: Gamma 2.2 curve with a linear segment in the lower
 *                                range. Used for BT.2020 with 12 bits per
 *                                component. Since: 1.6.
 * @SPA_VIDEO_TRANSFER_ADOBERGB: Gamma 2.19921875. Since: 1.8
 *
 * The video transfer function defines the formula for converting between
 * non-linear RGB (R'G'B') and linear RGB
 */
enum spa_video_transfer_function {
	SPA_VIDEO_TRANSFER_UNKNOWN = 0,
	SPA_VIDEO_TRANSFER_GAMMA10,
	SPA_VIDEO_TRANSFER_GAMMA18,
	SPA_VIDEO_TRANSFER_GAMMA20,
	SPA_VIDEO_TRANSFER_GAMMA22,
	SPA_VIDEO_TRANSFER_BT709,
	SPA_VIDEO_TRANSFER_SMPTE240M,
	SPA_VIDEO_TRANSFER_SRGB,
	SPA_VIDEO_TRANSFER_GAMMA28,
	SPA_VIDEO_TRANSFER_LOG100,
	SPA_VIDEO_TRANSFER_LOG316,
	SPA_VIDEO_TRANSFER_BT2020_12,
	SPA_VIDEO_TRANSFER_ADOBERGB
};

/**
 * spa_video_color_primaries:
 * @SPA_VIDEO_COLOR_PRIMARIES_UNKNOWN: unknown color primaries
 * @SPA_VIDEO_COLOR_PRIMARIES_BT709: BT709 primaries
 * @SPA_VIDEO_COLOR_PRIMARIES_BT470M: BT470M primaries
 * @SPA_VIDEO_COLOR_PRIMARIES_BT470BG: BT470BG primaries
 * @SPA_VIDEO_COLOR_PRIMARIES_SMPTE170M: SMPTE170M primaries
 * @SPA_VIDEO_COLOR_PRIMARIES_SMPTE240M: SMPTE240M primaries
 * @SPA_VIDEO_COLOR_PRIMARIES_FILM: Generic film
 * @SPA_VIDEO_COLOR_PRIMARIES_BT2020: BT2020 primaries. Since: 1.6.
 * @SPA_VIDEO_COLOR_PRIMARIES_ADOBERGB: Adobe RGB primaries. Since: 1.8
 *
 * The color primaries define the how to transform linear RGB values to and from
 * the CIE XYZ colorspace.
 */
enum spa_video_color_primaries {
	SPA_VIDEO_COLOR_PRIMARIES_UNKNOWN = 0,
	SPA_VIDEO_COLOR_PRIMARIES_BT709,
	SPA_VIDEO_COLOR_PRIMARIES_BT470M,
	SPA_VIDEO_COLOR_PRIMARIES_BT470BG,
	SPA_VIDEO_COLOR_PRIMARIES_SMPTE170M,
	SPA_VIDEO_COLOR_PRIMARIES_SMPTE240M,
	SPA_VIDEO_COLOR_PRIMARIES_FILM,
	SPA_VIDEO_COLOR_PRIMARIES_BT2020,
	SPA_VIDEO_COLOR_PRIMARIES_ADOBERGB
};

/**
 * spa_video_colorimetry:
 * @range: the color range. This is the valid range for the samples.
 *         It is used to convert the samples to Y'PbPr values.
 * @matrix: the color matrix. Used to convert between Y'PbPr and
 *          non-linear RGB (R'G'B')
 * @transfer: the transfer function. used to convert between R'G'B' and RGB
 * @primaries: color primaries. used to convert between R'G'B' and CIE XYZ
 *
 * Structure describing the color info.
 */
struct spa_video_colorimetry {
	enum spa_video_color_range range;
	enum spa_video_color_matrix matrix;
	enum spa_video_transfer_function transfer;
	enum spa_video_color_primaries primaries;
};

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __SPA_VIDEO_COLOR_H__ */
