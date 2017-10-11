//  Copyright (c) 2017 Hartmut Kaiser
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(PHYLANX_PRIMITIVES_PARALLEL_BLOCK_OPERATION_OCT_08_2017_0807PM)
#define PHYLANX_PRIMITIVES_PARALLEL_BLOCK_OPERATION_OCT_08_2017_0807PM

#include <phylanx/config.hpp>
#include <phylanx/ast/node.hpp>
#include <phylanx/ir/node_data.hpp>
#include <phylanx/execution_tree/primitives/base_primitive.hpp>
#include <phylanx/util/optional.hpp>
#include <phylanx/util/serialization/optional.hpp>

#include <hpx/include/components.hpp>

#include <vector>

namespace phylanx { namespace execution_tree { namespace primitives
{
    class HPX_COMPONENT_EXPORT parallel_block_operation
      : public base_primitive
      , public hpx::components::component_base<parallel_block_operation>
    {
        using operands_type = std::vector<primitive_result_type>;

    public:
        static match_pattern_type const match_data;

        parallel_block_operation() = default;

        parallel_block_operation(std::vector<primitive_argument_type>&& operands);

        hpx::future<primitive_result_type> eval() const override;

    private:
        std::vector<primitive_argument_type> operands_;
    };
}}}

#endif


