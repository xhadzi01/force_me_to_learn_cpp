#include <optional>
#include <string>
#include <variant>

using ResultError = std::optional<std::string>;

template <typename T>
class Result final
{
	template <typename T>
	using ResultValue_T = T;
	struct ResultError_T
	{
		std::string error;
	};

	Result(const ResultError_T& err): res{err} {}

public:
	~Result() = default;

	Result(const T& val): res{val} {}

	static auto with_value(const T& val) -> Result { return Result{val}; }
	static auto with_error(const std::string& err) -> Result { return Result{ResultError_T{err}}; }

	Result(const Result&) = delete;
	Result(const Result&&) = delete;
	Result& operator =(const Result&) = delete;
	Result& operator =(const Result&&) = delete;

	auto value() const -> T { return std::get<ResultValue_T<T>>(res);	};
	auto error() const -> std::string { return std::get<ResultError_T>(res).error; };
	auto is_valid() const noexcept -> bool { return std::holds_alternative<ResultValue_T<T>>(res); }

private:
	std::variant<ResultValue_T<T>, ResultError_T> res;
};