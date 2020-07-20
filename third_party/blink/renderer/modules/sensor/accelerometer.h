// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_SENSOR_ACCELEROMETER_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_SENSOR_ACCELEROMETER_H_

#include "third_party/blink/renderer/bindings/modules/v8/v8_spatial_sensor_options.h"
#include "third_party/blink/renderer/modules/sensor/sensor.h"

namespace blink {

class Accelerometer : public Sensor {
  DEFINE_WRAPPERTYPEINFO();

 public:
  static Accelerometer* Create(ExecutionContext*,
                               const SpatialSensorOptions*,
                               ExceptionState&);
  static Accelerometer* Create(ExecutionContext*, ExceptionState&);

  Accelerometer(ExecutionContext*,
                const SpatialSensorOptions*,
                ExceptionState&,
                device::mojom::blink::SensorType,
                const Vector<mojom::blink::FeaturePolicyFeature>&);

  base::Optional<double> x() const;
  base::Optional<double> y() const;
  base::Optional<double> z() const;
  // TODO(crbug.com/1060971): Remove |is_null| version.
  double x(bool& is_null) const;  // DEPRECATED
  double y(bool& is_null) const;  // DEPRECATED
  double z(bool& is_null) const;  // DEPRECATED

  void Trace(Visitor*) override;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_SENSOR_ACCELEROMETER_H_
