#include "esphome.h"

class TotalDailyCost : public Component, public Sensor
{
public:
  void setup() override
  {
    socket_total_daily_energy->add_on_state_callback([this](float value)
                                                     { this->process_new_state_(value); });
  }

  void process_new_state_(float state)
  {
    auto kwh_price_cents_state = id(kwh_price_cents).state;

    if (!isnan(state) && !isnan(kwh_price_cents_state))
    {
      float socket_total_daily_energy_delta;

      // Total daily energy was reset
      if (state < this->last_total_daily_energy_state_)
      {
        this->total_cost_ = 0;
        this->last_total_daily_energy_state_ = state;
        socket_total_daily_energy_delta = state;
      }
      else
      {
        socket_total_daily_energy_delta = state - this->last_total_daily_energy_state_;
      }

      this->total_cost_ += socket_total_daily_energy_delta * (kwh_price_cents_state / 100);
      this->last_total_daily_energy_state_ = state;

      publish_state(total_cost_);
    }
  };

private:
  const char *const TAG = "total_daily_cost";

protected:
  float total_cost_{0.0f};
  float last_total_daily_energy_state_{0.0f};
};
