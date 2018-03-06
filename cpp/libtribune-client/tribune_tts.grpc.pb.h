// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: tribune_tts.proto
// Original file comments:
// Techmo Tribune TTS API  
// version: 1.1.0   
// authors: Dawid Skurzok, Paweł Jaciów  
// date:    2018-01-25  
#ifndef GRPC_tribune_5ftts_2eproto__INCLUDED
#define GRPC_tribune_5ftts_2eproto__INCLUDED

#include "tribune_tts.pb.h"

#include <grpc++/impl/codegen/async_stream.h>
#include <grpc++/impl/codegen/async_unary_call.h>
#include <grpc++/impl/codegen/method_handler_impl.h>
#include <grpc++/impl/codegen/proto_utils.h>
#include <grpc++/impl/codegen/rpc_method.h>
#include <grpc++/impl/codegen/service_type.h>
#include <grpc++/impl/codegen/status.h>
#include <grpc++/impl/codegen/stub_options.h>
#include <grpc++/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class RpcService;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace techmo {
namespace tribune {

// Service that implements Techmo Text-To-Speech (TTS) API.
//
// Service's `Synthesize` method accepts `SynthesizeRequest` object which contains whole phrase to be synthesized.  
// You have to put the phrase as a string in `text` field of `SynthesizeRequest`. The string has to be in orthographic form. In that string you can use several special tags which can be interpreted. Tags have to be in from `<tag>something special</tag>` and can occur in any place in text. Currently interpreted tags are:
//
// | Tag | Description | Example (input) | Example (output) |
// | --- | ----------- | --------------- | ---------------- |
// | **cardinal** | *cardinal number* | `<cardinal>7</cardinal>` | *siedem* |
// | **signed** | *number with sign* | `<signed>-15</signed>` | *minus piętnaście* |
// | **ordinal** | *ordinal number* | `<ordinal>1</ordinal>` | *pierwszy* |
// | **fraction** | *fractional number* | `<fraction>3/4</fraction>` | *trzy czwarte* |
// | **postal** | *postal code* | `<postal>30-020</postal>` | *trzydzieści zero dwadzieścia* |
// | **time** | *time* | `<time>22:00</time>` | *dwudziesta druga* |
// | **date** | *date* | `<date>12/05/2001</date>` | *dwunasty maja dwa tysiące jeden* |
//
// Note: when interpreting tags only nominal case is supported at the moment.
//
// You can set `SynthesizeConfig`'s fields to specify parameters of synthesis. Currently supported option is only `sample_rate_hertz`, which is desired sampling frequency (in hertz) of synthesized audio.
//
// `SynthesizeRequest` can be sent to the service via gRPC insecure channel (that does not require authentication).
//
// `Synthesize` returns synthesized audio in `SynthesizeResponse` as a stream. When reading from the stream you have to check if `SynthesizeResponse` contains `error` field. If it does you can print its `code` and `description`. No `error` field in `SynthesizeResponse` means everything worked fine and its `audio` contains byte `content` that can be appended to received audio samples with `sample_rate_hertz` sampling frequency in hertz. When receiving `SynthesizeResponse` with `audio` you have to check if its `end_of_stream` flag is set to true. When it is set to true it means service has fnished synthesis and you can save your wave file with received synthesized audio content.
class TTS final {
 public:
  static constexpr char const* service_full_name() {
    return "techmo.tribune.TTS";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    // Returns audio signal with synthesized speech, given text and optional configuration.
    std::unique_ptr< ::grpc::ClientReaderInterface< ::techmo::tribune::SynthesizeResponse>> Synthesize(::grpc::ClientContext* context, const ::techmo::tribune::SynthesizeRequest& request) {
      return std::unique_ptr< ::grpc::ClientReaderInterface< ::techmo::tribune::SynthesizeResponse>>(SynthesizeRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::techmo::tribune::SynthesizeResponse>> AsyncSynthesize(::grpc::ClientContext* context, const ::techmo::tribune::SynthesizeRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::techmo::tribune::SynthesizeResponse>>(AsyncSynthesizeRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::techmo::tribune::SynthesizeResponse>> PrepareAsyncSynthesize(::grpc::ClientContext* context, const ::techmo::tribune::SynthesizeRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::techmo::tribune::SynthesizeResponse>>(PrepareAsyncSynthesizeRaw(context, request, cq));
    }
  private:
    virtual ::grpc::ClientReaderInterface< ::techmo::tribune::SynthesizeResponse>* SynthesizeRaw(::grpc::ClientContext* context, const ::techmo::tribune::SynthesizeRequest& request) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::techmo::tribune::SynthesizeResponse>* AsyncSynthesizeRaw(::grpc::ClientContext* context, const ::techmo::tribune::SynthesizeRequest& request, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::techmo::tribune::SynthesizeResponse>* PrepareAsyncSynthesizeRaw(::grpc::ClientContext* context, const ::techmo::tribune::SynthesizeRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    std::unique_ptr< ::grpc::ClientReader< ::techmo::tribune::SynthesizeResponse>> Synthesize(::grpc::ClientContext* context, const ::techmo::tribune::SynthesizeRequest& request) {
      return std::unique_ptr< ::grpc::ClientReader< ::techmo::tribune::SynthesizeResponse>>(SynthesizeRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::techmo::tribune::SynthesizeResponse>> AsyncSynthesize(::grpc::ClientContext* context, const ::techmo::tribune::SynthesizeRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::techmo::tribune::SynthesizeResponse>>(AsyncSynthesizeRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::techmo::tribune::SynthesizeResponse>> PrepareAsyncSynthesize(::grpc::ClientContext* context, const ::techmo::tribune::SynthesizeRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::techmo::tribune::SynthesizeResponse>>(PrepareAsyncSynthesizeRaw(context, request, cq));
    }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    ::grpc::ClientReader< ::techmo::tribune::SynthesizeResponse>* SynthesizeRaw(::grpc::ClientContext* context, const ::techmo::tribune::SynthesizeRequest& request) override;
    ::grpc::ClientAsyncReader< ::techmo::tribune::SynthesizeResponse>* AsyncSynthesizeRaw(::grpc::ClientContext* context, const ::techmo::tribune::SynthesizeRequest& request, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncReader< ::techmo::tribune::SynthesizeResponse>* PrepareAsyncSynthesizeRaw(::grpc::ClientContext* context, const ::techmo::tribune::SynthesizeRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::RpcMethod rpcmethod_Synthesize_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    // Returns audio signal with synthesized speech, given text and optional configuration.
    virtual ::grpc::Status Synthesize(::grpc::ServerContext* context, const ::techmo::tribune::SynthesizeRequest* request, ::grpc::ServerWriter< ::techmo::tribune::SynthesizeResponse>* writer);
  };
  template <class BaseClass>
  class WithAsyncMethod_Synthesize : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_Synthesize() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_Synthesize() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Synthesize(::grpc::ServerContext* context, const ::techmo::tribune::SynthesizeRequest* request, ::grpc::ServerWriter< ::techmo::tribune::SynthesizeResponse>* writer) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestSynthesize(::grpc::ServerContext* context, ::techmo::tribune::SynthesizeRequest* request, ::grpc::ServerAsyncWriter< ::techmo::tribune::SynthesizeResponse>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(0, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_Synthesize<Service > AsyncService;
  template <class BaseClass>
  class WithGenericMethod_Synthesize : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_Synthesize() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_Synthesize() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Synthesize(::grpc::ServerContext* context, const ::techmo::tribune::SynthesizeRequest* request, ::grpc::ServerWriter< ::techmo::tribune::SynthesizeResponse>* writer) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  typedef Service StreamedUnaryService;
  template <class BaseClass>
  class WithSplitStreamingMethod_Synthesize : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithSplitStreamingMethod_Synthesize() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::SplitServerStreamingHandler< ::techmo::tribune::SynthesizeRequest, ::techmo::tribune::SynthesizeResponse>(std::bind(&WithSplitStreamingMethod_Synthesize<BaseClass>::StreamedSynthesize, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithSplitStreamingMethod_Synthesize() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status Synthesize(::grpc::ServerContext* context, const ::techmo::tribune::SynthesizeRequest* request, ::grpc::ServerWriter< ::techmo::tribune::SynthesizeResponse>* writer) final override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with split streamed
    virtual ::grpc::Status StreamedSynthesize(::grpc::ServerContext* context, ::grpc::ServerSplitStreamer< ::techmo::tribune::SynthesizeRequest,::techmo::tribune::SynthesizeResponse>* server_split_streamer) = 0;
  };
  typedef WithSplitStreamingMethod_Synthesize<Service > SplitStreamedService;
  typedef WithSplitStreamingMethod_Synthesize<Service > StreamedService;
};

}  // namespace tribune
}  // namespace techmo


#endif  // GRPC_tribune_5ftts_2eproto__INCLUDED
