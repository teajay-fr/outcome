+++
title = "`default_policy<T, EC, EP>`"
description = "A type alias to a no-value policy selected based on traits matching of `T`, `EC` and `EP`."
+++

A type alias to a no-value policy selected based on traits matching of `T`, `EC` and `EP`. It is defined as follows:

1. If `EC` and `EP` is `void`, choose {{% api "terminate" %}}.

2. If {{% api "has_error_code<T>" %}} true for `EC`, choose {{% api "error_code_throw_as_system_error<T, EC, EP>" %}} for `basic_outcome` or {{% api "error_code_throw_as_system_error<T, EC, void>" %}} for `basic_result`.

3. If {{% api "has_exception_ptr<T>" %}} true for `EC` or `EP`, choose {{% api "exception_ptr_rethrow<T, EC, EP>" %}} for `basic_outcome` or {{% api "exception_ptr_rethrow<T, EC, void>" %}} for `basic_result`.

4. Else choose {{% api "fail_to_compile_observers" %}}, which fails the build with a useful message.

*Namespace*: `OUTCOME_V2_NAMESPACE::policy`

*Header*: `<outcome/std_result.hpp>`