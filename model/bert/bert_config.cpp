#include "bert_config.h"

namespace BERT
{
    BertConfig::BertConfig(int vocab_size,
            int hidden_size,
            int num_hidden_layers,
            int num_attention_heads,
            int intermediate_size,
            std::string hidden_act,
            float hidden_dropout_prob,
            float attention_probs_dropout_prob,
            float max_position_embeddings,
            int type_vocab_size,
            float initializer_range)
    {
        this->vocab_size = vocab_size;
        this->hidden_size = hidden_size;
        this->num_hidden_layers = num_hidden_layers;
        this->num_attention_heads = num_attention_heads;
        this->intermediate_size = intermediate_size;
        this->hidden_act = hidden_act;
        this->hidden_dropout_prob = hidden_dropout_prob;
        this->attention_probs_dropout_prob = attention_probs_dropout_prob;
        this->max_position_embeddings = max_position_embeddings;
        this->type_vocab_size = type_vocab_size;
        this->initializer_range = initializer_range;
        this->layer_norm_eps = 1e-12;
        this->output_attentions = true;
    };


    BertConfig::BertConfig():hidden_size(768),num_hidden_layers(12),
        num_attention_heads(12), intermediate_size(3072),
        hidden_act("gelu"), hidden_dropout_prob(0.1f),
        attention_probs_dropout_prob(0.1f), max_position_embeddings(512),
        type_vocab_size(16), initializer_range(0.02){
            this->layer_norm_eps = 1e-12;
            this->output_attentions = true;
        };


    BertConfig BertConfig::fromMap(
        std::map<std::string, std::unique_ptr<MapFieldInterface>> mapObject){
        BertConfig ret;

        ret.vocab_size = GET_V(mapObject, int, "vocab_size");
        ret.hidden_size = GET_V(mapObject, int, "hidden_size");
        ret.num_hidden_layers = GET_V(mapObject, int, "num_hidden_layers");
        ret.num_attention_heads = GET_V(mapObject, int, "num_attention_heads");
        ret.intermediate_size = GET_V(mapObject, int, "intermediate_size");
        ret.hidden_act = GET_V(mapObject, std::string, "hidden_act");
        ret.hidden_dropout_prob = GET_V(mapObject, float, "hidden_dropout_prob");
        ret.attention_probs_dropout_prob = GET_V(mapObject, float, "attention_probs_dropout_prob");
        ret.max_position_embeddings = GET_V(mapObject, int, "max_position_embeddings");
        ret.type_vocab_size = GET_V(mapObject, int, "type_vocab_size");
        ret.initializer_range = GET_V(mapObject, float, "initializer_range");

        ret.layer_norm_eps = 1e-12;
        ret.output_attentions = true;
        return ret;
    }


    BertConfig BertConfig::fromJson(nlohmann::json jsonObject){
        BertConfig ret;

        ret.vocab_size = jsonObject["vocab_size"];
        ret.hidden_size = jsonObject["hidden_size"];
        ret.num_hidden_layers = jsonObject["num_hidden_layers"];
        ret.num_attention_heads = jsonObject["num_attention_heads"];
        ret.intermediate_size = jsonObject["intermediate_size"];
        ret.hidden_act = jsonObject["hidden_act"];
        ret.hidden_dropout_prob = jsonObject["hidden_dropout_prob"];
        ret.attention_probs_dropout_prob = jsonObject["attention_probs_dropout_prob"];
        ret.max_position_embeddings = jsonObject["max_position_embeddings"];
        ret.type_vocab_size = jsonObject["type_vocab_size"];
        ret.initializer_range = jsonObject["initializer_range"];

        ret.layer_norm_eps = 1e-12;
        ret.output_attentions = true;
        return ret;
    }


    std::map<std::string, std::unique_ptr<MapFieldInterface>> BertConfig::toMap(){
        std::map<std::string, std::unique_ptr<MapFieldInterface>> ret;

        ret["vocab_size"] = MAKE_V(int, this->vocab_size);
        ret["hidden_size"] = MAKE_V(int, this->hidden_size);
        ret["num_hidden_layers"] = MAKE_V(int, this->num_hidden_layers);
        ret["num_attention_heads"] = MAKE_V(int, this->num_attention_heads);
        ret["intermediate_size"] = MAKE_V(int, this->intermediate_size);
        ret["hidden_act"] = MAKE_V(std::string, this->hidden_act);
        ret["hidden_dropout_prob"] = MAKE_V(float, this->hidden_dropout_prob);
        ret["attention_probs_dropout_prob"] = MAKE_V(float, this->attention_probs_dropout_prob);
        ret["max_position_embeddings"] = MAKE_V(int, this->max_position_embeddings);
        ret["type_vocab_size"] = MAKE_V(int, this->type_vocab_size);
        ret["initializer_range"] = MAKE_V(float, this->initializer_range);
    }


    nlohmann::json BertConfig::toJson(){
        nlohmann::json ret;

        ret["vocab_size"] = this->vocab_size;
        ret["hidden_size"] = this->hidden_size;
        ret["num_hidden_layers"] = this->num_hidden_layers;
        ret["num_attention_heads"] = this->num_attention_heads;
        ret["intermediate_size"] = this->intermediate_size;
        ret["hidden_act"] = this->hidden_act;
        ret["hidden_dropout_prob"] = this->hidden_dropout_prob;
        ret["attention_probs_dropout_prob"] = this->attention_probs_dropout_prob;
        ret["max_position_embeddings"] = this->max_position_embeddings;
        ret["type_vocab_size"] = this->type_vocab_size;
        ret["initializer_range"] = this->initializer_range;

        return ret;
    }
}