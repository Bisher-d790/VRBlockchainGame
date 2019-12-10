package com.academy.contracts;

import io.reactivex.Flowable;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.concurrent.Callable;
import org.web3j.abi.EventEncoder;
import org.web3j.abi.TypeReference;
import org.web3j.abi.datatypes.Address;
import org.web3j.abi.datatypes.DynamicArray;
import org.web3j.abi.datatypes.Event;
import org.web3j.abi.datatypes.Function;
import org.web3j.abi.datatypes.Type;
import org.web3j.abi.datatypes.Utf8String;
import org.web3j.abi.datatypes.generated.Uint16;
import org.web3j.abi.datatypes.generated.Uint256;
import org.web3j.abi.datatypes.generated.Uint32;
import org.web3j.abi.datatypes.generated.Uint8;
import org.web3j.crypto.Credentials;
import org.web3j.protocol.Web3j;
import org.web3j.protocol.core.DefaultBlockParameter;
import org.web3j.protocol.core.RemoteCall;
import org.web3j.protocol.core.methods.request.EthFilter;
import org.web3j.protocol.core.methods.response.Log;
import org.web3j.protocol.core.methods.response.TransactionReceipt;
import org.web3j.tuples.generated.Tuple7;
import org.web3j.tx.Contract;
import org.web3j.tx.TransactionManager;
import org.web3j.tx.gas.ContractGasProvider;

/**
 * <p>Auto generated code.
 * <p><strong>Do not modify!</strong>
 * <p>Please use the <a href="https://docs.web3j.io/command_line.html">web3j command line tools</a>,
 * or the org.web3j.codegen.SolidityFunctionWrapperGenerator in the 
 * <a href="https://github.com/web3j/web3j/tree/master/codegen">codegen module</a> to update.
 *
 * <p>Generated with web3j version 4.1.0.
 */
public class WeaponFactory extends Contract {
    private static final String BINARY = "60806040526010600055662386f26fc1000060015566038d7ea4c6800060055534801561002b57600080fd5b50610f538061003b6000396000f3006080604052600436106100c45763ffffffff7c01000000000000000000000000000000000000000000000000000000006000350416630187fcf381146100c9578063095ea7b31461013a5780630ce90ec2146101535780631e3b38221461015e57806323b872dd14610192578063555e73c8146101af5780636352211e1461028157806370a08231146102995780638c2f661e146102cc5780639e41b73f146102ea578063a800a6ce14610302578063b0ed0dc714610360578063c39cbef114610388575b600080fd5b3480156100d557600080fd5b506100ea600160a060020a03600435166103ac565b60408051602080825283518183015283519192839290830191858101910280838360005b8381101561012657818101518382015260200161010e565b505050509050019250505060405180910390f35b610151600160a060020a036004351660243561046a565b005b6101516004356104f6565b34801561016a57600080fd5b506101766004356105d8565b60408051600160a060020a039092168252519081900360200190f35b610151600160a060020a03600435811690602435166044356105f3565b3480156101bb57600080fd5b506101c7600435610649565b6040805160ff881660208083019190915263ffffffff8089169383019390935291861660608201526080810185905261ffff80851660a0830152831660c082015260e08082528951908201528851909182916101008301918b019080838360005b83811015610240578181015183820152602001610228565b50505050905090810190601f16801561026d5780820380516001836020036101000a031916815260200191505b509850505050505050505060405180910390f35b34801561028d57600080fd5b50610176600435610739565b3480156102a557600080fd5b506102ba600160a060020a0360043516610754565b60408051918252519081900360200190f35b3480156102d857600080fd5b5061015160043560ff6024351661076f565b3480156102f657600080fd5b506101c7600435610811565b34801561030e57600080fd5b506040805160206004803580820135601f81018490048402850184019095528484526102ba9436949293602493928401919081908401838280828437509497505050923560ff16935061097b92505050565b34801561036c57600080fd5b50610151602460048035828101929101359060ff903516610bd9565b34801561039457600080fd5b50610151600480359060248035908101910135610c34565b6060806000806004600086600160a060020a0316600160a060020a0316815260200190815260200160002054604051908082528060200260200182016040528015610401578160200160208202803883390190505b50925060009150600090505b60025481101561046157600081815260036020526040902054600160a060020a03868116911614156104595780838381518110151561044857fe5b602090810290910101526001909101905b60010161040d565b50909392505050565b6000818152600360205260409020548190600160a060020a0316331461048f57600080fd5b600082815260066020526040808220805473ffffffffffffffffffffffffffffffffffffffff1916600160a060020a0387169081179091559051849233917f8c5be1e5ebec7d5bd14f71427d1e84f3dd0314c0f7b2291e5b200ac8c7c3b9259190a4505050565b600554341461050457600080fd5b610541600160028381548110151561051857fe5b600091825260209091206001600490920201015463ffffffff61010090910481169190610cca16565b600280548390811061054f57fe5b906000526020600020906004020160010160016101000a81548163ffffffff021916908363ffffffff1602179055506105b2600a60028381548110151561059257fe5b906000526020600020906004020160020154610ce990919063ffffffff16565b60028054839081106105c057fe5b90600052602060002090600402016002018190555050565b600360205260009081526040902054600160a060020a031681565b600081815260036020526040902054600160a060020a031633148061062e5750600081815260066020526040902054600160a060020a031633145b151561063957600080fd5b610644838383610cf8565b505050565b600280548290811061065757fe5b60009182526020918290206004919091020180546040805160026001841615610100026000190190931692909204601f8101859004850283018501909152808252919350918391908301828280156106f05780601f106106c5576101008083540402835291602001916106f0565b820191906000526020600020905b8154815290600101906020018083116106d357829003601f168201915b50505060018401546002850154600390950154939460ff82169463ffffffff6101008404811695506501000000000090930490921692509061ffff808216916201000090041687565b600090815260036020526040902054600160a060020a031690565b600160a060020a031660009081526004602052604090205490565b6014828160028281548110151561078257fe5b6000918252602090912060049091020160010154610100900463ffffffff1610156107ac57600080fd5b6000848152600360205260409020548490600160a060020a031633146107d157600080fd5b836002868154811015156107e157fe5b906000526020600020906004020160010160006101000a81548160ff021916908360ff1602179055505050505050565b6060600080600080600080610824610de2565b600280548a90811061083257fe5b6000918252602091829020604080516004939093029091018054600260018216156101009081026000190190921604601f81018690049095028401810190925260e08301848152929390928492909184918401828280156108d45780601f106108a9576101008083540402835291602001916108d4565b820191906000526020600020905b8154815290600101906020018083116108b757829003601f168201915b5050509183525050600182015460ff811660208084019190915263ffffffff610100830481166040808601919091526501000000000090930416606080850191909152600285015460808086019190915260039095015461ffff80821660a080880191909152620100009092041660c095860152865192870151938701519187015195870151908701519690940151919f929e509c50929a50909850919650945092505050565b6040805160e08101825283815260ff831660208083019190915260019282018390524263ffffffff16606083015260146080830152600060a0830181905260c0830181905260028054808601808355918352845180519396879690959394909360049093027f405787fa12a823e0f2b7631cc41b3ba8828b3321ca811111fa75cd3aa3bb5ace0192610a11928492910190610e1e565b5060208281015160018381018054604080880151606089015160ff1990931660ff9096169590951764ffffffff00191661010063ffffffff968716021768ffffffff000000000019166501000000000092861692909202919091179091556080860151600286015560a08601516003958601805460c09098015161ffff1990981661ffff9283161763ffff000019166201000092909816919091029690961790955595909403600081815292825283832080543373ffffffffffffffffffffffffffffffffffffffff1990911681179091558352600490915291902054909350610afd929091610ce916565b6004600033600160a060020a0316600160a060020a03168152602001908152602001600020819055507f9d26e4755409d8cdc484d7a47f131ce8ef4e26c993833d9e0b58fa7a930fdb6d81858560405180848152602001806020018360ff168152602001828103825284818151815260200191508051906020019080838360005b83811015610b96578181015183820152602001610b7e565b50505050905090810190601f168015610bc35780820380516001836020036101000a031916815260200191505b5094505050505060405180910390a19392505050565b3360009081526004602052604090205415610bf357600080fd5b610c2e83838080601f0160208091040260200160405190810160405280939291908181526020018383808284375087945061097b9350505050565b50505050565b60028381600282815481101515610c4757fe5b6000918252602090912060049091020160010154610100900463ffffffff161015610c7157600080fd5b6000858152600360205260409020548590600160a060020a03163314610c9657600080fd5b8484600288815481101515610ca757fe5b60009182526020909120610cc19360049092020191610e9c565b50505050505050565b600082820163ffffffff8085169082161015610ce257fe5b9392505050565b600082820183811015610ce257fe5b600160a060020a038216600090815260046020526040902054610d2290600163ffffffff610ce916565b600160a060020a038316600090815260046020526040808220929092553381522054610d5590600163ffffffff610dd016565b3360009081526004602090815260408083209390935583825260039052818120805473ffffffffffffffffffffffffffffffffffffffff1916600160a060020a038681169182179092559251849392918716917fddf252ad1be2c89b69c2b068fc378daa952ba7f163c4a11628f55a4df523b3ef91a4505050565b600082821115610ddc57fe5b50900390565b6040805160e081018252606080825260006020830181905292820183905281018290526080810182905260a0810182905260c081019190915290565b828054600181600116156101000203166002900490600052602060002090601f016020900481019282601f10610e5f57805160ff1916838001178555610e8c565b82800160010185558215610e8c579182015b82811115610e8c578251825591602001919060010190610e71565b50610e98929150610f0a565b5090565b828054600181600116156101000203166002900490600052602060002090601f016020900481019282601f10610edd5782800160ff19823516178555610e8c565b82800160010185558215610e8c579182015b82811115610e8c578235825591602001919060010190610eef565b610f2491905b80821115610e985760008155600101610f10565b905600a165627a7a72305820b43a5e65a5b1f9aca035d0ae9be813207b6e03e0c039da38ffcef0d7d7976b350029";

    public static final String FUNC_GETWEAPONBYOWNER = "getWeaponByOwner";

    public static final String FUNC_APPROVE = "approve";

    public static final String FUNC_LEVELUP = "levelUp";

    public static final String FUNC_WEAPONTOOWNER = "WeaponToOwner";

    public static final String FUNC_TRANSFERFROM = "transferFrom";

    public static final String FUNC_WEAPONS = "weapons";

    public static final String FUNC_OWNEROF = "ownerOf";

    public static final String FUNC_BALANCEOF = "balanceOf";

    public static final String FUNC_CHANGECREDS = "changeCreds";

    public static final String FUNC_GETWEAPON = "getWeapon";

    public static final String FUNC__CREATEWEAPON = "_createWeapon";

    public static final String FUNC__NEWPLAYERCREATE = "_newPlayerCreate";

    public static final String FUNC_CHANGENAME = "changeName";

    public static final Event NEWWEAPON_EVENT = new Event("NewWeapon", 
            Arrays.<TypeReference<?>>asList(new TypeReference<Uint256>() {}, new TypeReference<Utf8String>() {}, new TypeReference<Uint256>() {}));
    ;

    public static final Event TRANSFER_EVENT = new Event("Transfer", 
            Arrays.<TypeReference<?>>asList(new TypeReference<Address>(true) {}, new TypeReference<Address>(true) {}, new TypeReference<Uint256>(true) {}));
    ;

    public static final Event APPROVAL_EVENT = new Event("Approval", 
            Arrays.<TypeReference<?>>asList(new TypeReference<Address>(true) {}, new TypeReference<Address>(true) {}, new TypeReference<Uint256>(true) {}));
    ;

    @Deprecated
    protected WeaponFactory(String contractAddress, Web3j web3j, Credentials credentials, BigInteger gasPrice, BigInteger gasLimit) {
        super(BINARY, contractAddress, web3j, credentials, gasPrice, gasLimit);
    }

    protected WeaponFactory(String contractAddress, Web3j web3j, Credentials credentials, ContractGasProvider contractGasProvider) {
        super(BINARY, contractAddress, web3j, credentials, contractGasProvider);
    }

    @Deprecated
    protected WeaponFactory(String contractAddress, Web3j web3j, TransactionManager transactionManager, BigInteger gasPrice, BigInteger gasLimit) {
        super(BINARY, contractAddress, web3j, transactionManager, gasPrice, gasLimit);
    }

    protected WeaponFactory(String contractAddress, Web3j web3j, TransactionManager transactionManager, ContractGasProvider contractGasProvider) {
        super(BINARY, contractAddress, web3j, transactionManager, contractGasProvider);
    }

    public RemoteCall<List> getWeaponByOwner(String _owner) {
        final Function function = new Function(FUNC_GETWEAPONBYOWNER, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Address(_owner)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<DynamicArray<Uint256>>() {}));
        return new RemoteCall<List>(
                new Callable<List>() {
                    @Override
                    @SuppressWarnings("unchecked")
                    public List call() throws Exception {
                        List<Type> result = (List<Type>) executeCallSingleValueReturn(function, List.class);
                        return convertToNative(result);
                    }
                });
    }

    public RemoteCall<TransactionReceipt> approve(String _approved, BigInteger _tokenId, BigInteger weiValue) {
        final Function function = new Function(
                FUNC_APPROVE, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Address(_approved), 
                new org.web3j.abi.datatypes.generated.Uint256(_tokenId)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function, weiValue);
    }

    public RemoteCall<TransactionReceipt> levelUp(BigInteger _weaponId, BigInteger weiValue) {
        final Function function = new Function(
                FUNC_LEVELUP, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(_weaponId)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function, weiValue);
    }

    public RemoteCall<String> WeaponToOwner(BigInteger param0) {
        final Function function = new Function(FUNC_WEAPONTOOWNER, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(param0)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Address>() {}));
        return executeRemoteCallSingleValueReturn(function, String.class);
    }

    public RemoteCall<TransactionReceipt> transferFrom(String _from, String _to, BigInteger _tokenId, BigInteger weiValue) {
        final Function function = new Function(
                FUNC_TRANSFERFROM, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Address(_from), 
                new org.web3j.abi.datatypes.Address(_to), 
                new org.web3j.abi.datatypes.generated.Uint256(_tokenId)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function, weiValue);
    }

    public RemoteCall<Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger>> weapons(BigInteger param0) {
        final Function function = new Function(FUNC_WEAPONS, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(param0)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Utf8String>() {}, new TypeReference<Uint8>() {}, new TypeReference<Uint32>() {}, new TypeReference<Uint32>() {}, new TypeReference<Uint256>() {}, new TypeReference<Uint16>() {}, new TypeReference<Uint16>() {}));
        return new RemoteCall<Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger>>(
                new Callable<Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger>>() {
                    @Override
                    public Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger> call() throws Exception {
                        List<Type> results = executeCallMultipleValueReturn(function);
                        return new Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger>(
                                (String) results.get(0).getValue(), 
                                (BigInteger) results.get(1).getValue(), 
                                (BigInteger) results.get(2).getValue(), 
                                (BigInteger) results.get(3).getValue(), 
                                (BigInteger) results.get(4).getValue(), 
                                (BigInteger) results.get(5).getValue(), 
                                (BigInteger) results.get(6).getValue());
                    }
                });
    }

    public RemoteCall<String> ownerOf(BigInteger _tokenId) {
        final Function function = new Function(FUNC_OWNEROF, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(_tokenId)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Address>() {}));
        return executeRemoteCallSingleValueReturn(function, String.class);
    }

    public RemoteCall<BigInteger> balanceOf(String _owner) {
        final Function function = new Function(FUNC_BALANCEOF, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Address(_owner)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Uint256>() {}));
        return executeRemoteCallSingleValueReturn(function, BigInteger.class);
    }

    public RemoteCall<TransactionReceipt> changeCreds(BigInteger _weaponId, BigInteger _newCreds) {
        final Function function = new Function(
                FUNC_CHANGECREDS, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(_weaponId), 
                new org.web3j.abi.datatypes.generated.Uint8(_newCreds)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger>> getWeapon(BigInteger _id) {
        final Function function = new Function(FUNC_GETWEAPON, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(_id)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Utf8String>() {}, new TypeReference<Uint8>() {}, new TypeReference<Uint32>() {}, new TypeReference<Uint32>() {}, new TypeReference<Uint256>() {}, new TypeReference<Uint16>() {}, new TypeReference<Uint16>() {}));
        return new RemoteCall<Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger>>(
                new Callable<Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger>>() {
                    @Override
                    public Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger> call() throws Exception {
                        List<Type> results = executeCallMultipleValueReturn(function);
                        return new Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger>(
                                (String) results.get(0).getValue(), 
                                (BigInteger) results.get(1).getValue(), 
                                (BigInteger) results.get(2).getValue(), 
                                (BigInteger) results.get(3).getValue(), 
                                (BigInteger) results.get(4).getValue(), 
                                (BigInteger) results.get(5).getValue(), 
                                (BigInteger) results.get(6).getValue());
                    }
                });
    }

    public RemoteCall<TransactionReceipt> _createWeapon(String _name, BigInteger _wepType) {
        final Function function = new Function(
                FUNC__CREATEWEAPON, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Utf8String(_name), 
                new org.web3j.abi.datatypes.generated.Uint8(_wepType)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<TransactionReceipt> _newPlayerCreate(String _name, BigInteger _wepType) {
        final Function function = new Function(
                FUNC__NEWPLAYERCREATE, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Utf8String(_name), 
                new org.web3j.abi.datatypes.generated.Uint8(_wepType)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<TransactionReceipt> changeName(BigInteger _weaponId, String _newName) {
        final Function function = new Function(
                FUNC_CHANGENAME, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(_weaponId), 
                new org.web3j.abi.datatypes.Utf8String(_newName)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public List<NewWeaponEventResponse> getNewWeaponEvents(TransactionReceipt transactionReceipt) {
        List<Contract.EventValuesWithLog> valueList = extractEventParametersWithLog(NEWWEAPON_EVENT, transactionReceipt);
        ArrayList<NewWeaponEventResponse> responses = new ArrayList<NewWeaponEventResponse>(valueList.size());
        for (Contract.EventValuesWithLog eventValues : valueList) {
            NewWeaponEventResponse typedResponse = new NewWeaponEventResponse();
            typedResponse.log = eventValues.getLog();
            typedResponse.weaponId = (BigInteger) eventValues.getNonIndexedValues().get(0).getValue();
            typedResponse.name = (String) eventValues.getNonIndexedValues().get(1).getValue();
            typedResponse.wepType = (BigInteger) eventValues.getNonIndexedValues().get(2).getValue();
            responses.add(typedResponse);
        }
        return responses;
    }

    public Flowable<NewWeaponEventResponse> newWeaponEventFlowable(EthFilter filter) {
        return web3j.ethLogFlowable(filter).map(new io.reactivex.functions.Function<Log, NewWeaponEventResponse>() {
            @Override
            public NewWeaponEventResponse apply(Log log) {
                Contract.EventValuesWithLog eventValues = extractEventParametersWithLog(NEWWEAPON_EVENT, log);
                NewWeaponEventResponse typedResponse = new NewWeaponEventResponse();
                typedResponse.log = log;
                typedResponse.weaponId = (BigInteger) eventValues.getNonIndexedValues().get(0).getValue();
                typedResponse.name = (String) eventValues.getNonIndexedValues().get(1).getValue();
                typedResponse.wepType = (BigInteger) eventValues.getNonIndexedValues().get(2).getValue();
                return typedResponse;
            }
        });
    }

    public Flowable<NewWeaponEventResponse> newWeaponEventFlowable(DefaultBlockParameter startBlock, DefaultBlockParameter endBlock) {
        EthFilter filter = new EthFilter(startBlock, endBlock, getContractAddress());
        filter.addSingleTopic(EventEncoder.encode(NEWWEAPON_EVENT));
        return newWeaponEventFlowable(filter);
    }

    public List<TransferEventResponse> getTransferEvents(TransactionReceipt transactionReceipt) {
        List<Contract.EventValuesWithLog> valueList = extractEventParametersWithLog(TRANSFER_EVENT, transactionReceipt);
        ArrayList<TransferEventResponse> responses = new ArrayList<TransferEventResponse>(valueList.size());
        for (Contract.EventValuesWithLog eventValues : valueList) {
            TransferEventResponse typedResponse = new TransferEventResponse();
            typedResponse.log = eventValues.getLog();
            typedResponse._from = (String) eventValues.getIndexedValues().get(0).getValue();
            typedResponse._to = (String) eventValues.getIndexedValues().get(1).getValue();
            typedResponse._tokenId = (BigInteger) eventValues.getIndexedValues().get(2).getValue();
            responses.add(typedResponse);
        }
        return responses;
    }

    public Flowable<TransferEventResponse> transferEventFlowable(EthFilter filter) {
        return web3j.ethLogFlowable(filter).map(new io.reactivex.functions.Function<Log, TransferEventResponse>() {
            @Override
            public TransferEventResponse apply(Log log) {
                Contract.EventValuesWithLog eventValues = extractEventParametersWithLog(TRANSFER_EVENT, log);
                TransferEventResponse typedResponse = new TransferEventResponse();
                typedResponse.log = log;
                typedResponse._from = (String) eventValues.getIndexedValues().get(0).getValue();
                typedResponse._to = (String) eventValues.getIndexedValues().get(1).getValue();
                typedResponse._tokenId = (BigInteger) eventValues.getIndexedValues().get(2).getValue();
                return typedResponse;
            }
        });
    }

    public Flowable<TransferEventResponse> transferEventFlowable(DefaultBlockParameter startBlock, DefaultBlockParameter endBlock) {
        EthFilter filter = new EthFilter(startBlock, endBlock, getContractAddress());
        filter.addSingleTopic(EventEncoder.encode(TRANSFER_EVENT));
        return transferEventFlowable(filter);
    }

    public List<ApprovalEventResponse> getApprovalEvents(TransactionReceipt transactionReceipt) {
        List<Contract.EventValuesWithLog> valueList = extractEventParametersWithLog(APPROVAL_EVENT, transactionReceipt);
        ArrayList<ApprovalEventResponse> responses = new ArrayList<ApprovalEventResponse>(valueList.size());
        for (Contract.EventValuesWithLog eventValues : valueList) {
            ApprovalEventResponse typedResponse = new ApprovalEventResponse();
            typedResponse.log = eventValues.getLog();
            typedResponse._owner = (String) eventValues.getIndexedValues().get(0).getValue();
            typedResponse._approved = (String) eventValues.getIndexedValues().get(1).getValue();
            typedResponse._tokenId = (BigInteger) eventValues.getIndexedValues().get(2).getValue();
            responses.add(typedResponse);
        }
        return responses;
    }

    public Flowable<ApprovalEventResponse> approvalEventFlowable(EthFilter filter) {
        return web3j.ethLogFlowable(filter).map(new io.reactivex.functions.Function<Log, ApprovalEventResponse>() {
            @Override
            public ApprovalEventResponse apply(Log log) {
                Contract.EventValuesWithLog eventValues = extractEventParametersWithLog(APPROVAL_EVENT, log);
                ApprovalEventResponse typedResponse = new ApprovalEventResponse();
                typedResponse.log = log;
                typedResponse._owner = (String) eventValues.getIndexedValues().get(0).getValue();
                typedResponse._approved = (String) eventValues.getIndexedValues().get(1).getValue();
                typedResponse._tokenId = (BigInteger) eventValues.getIndexedValues().get(2).getValue();
                return typedResponse;
            }
        });
    }

    public Flowable<ApprovalEventResponse> approvalEventFlowable(DefaultBlockParameter startBlock, DefaultBlockParameter endBlock) {
        EthFilter filter = new EthFilter(startBlock, endBlock, getContractAddress());
        filter.addSingleTopic(EventEncoder.encode(APPROVAL_EVENT));
        return approvalEventFlowable(filter);
    }

    @Deprecated
    public static WeaponFactory load(String contractAddress, Web3j web3j, Credentials credentials, BigInteger gasPrice, BigInteger gasLimit) {
        return new WeaponFactory(contractAddress, web3j, credentials, gasPrice, gasLimit);
    }

    @Deprecated
    public static WeaponFactory load(String contractAddress, Web3j web3j, TransactionManager transactionManager, BigInteger gasPrice, BigInteger gasLimit) {
        return new WeaponFactory(contractAddress, web3j, transactionManager, gasPrice, gasLimit);
    }

    public static WeaponFactory load(String contractAddress, Web3j web3j, Credentials credentials, ContractGasProvider contractGasProvider) {
        return new WeaponFactory(contractAddress, web3j, credentials, contractGasProvider);
    }

    public static WeaponFactory load(String contractAddress, Web3j web3j, TransactionManager transactionManager, ContractGasProvider contractGasProvider) {
        return new WeaponFactory(contractAddress, web3j, transactionManager, contractGasProvider);
    }

    public static RemoteCall<WeaponFactory> deploy(Web3j web3j, Credentials credentials, ContractGasProvider contractGasProvider) {
        return deployRemoteCall(WeaponFactory.class, web3j, credentials, contractGasProvider, BINARY, "");
    }

    @Deprecated
    public static RemoteCall<WeaponFactory> deploy(Web3j web3j, Credentials credentials, BigInteger gasPrice, BigInteger gasLimit) {
        return deployRemoteCall(WeaponFactory.class, web3j, credentials, gasPrice, gasLimit, BINARY, "");
    }

    public static RemoteCall<WeaponFactory> deploy(Web3j web3j, TransactionManager transactionManager, ContractGasProvider contractGasProvider) {
        return deployRemoteCall(WeaponFactory.class, web3j, transactionManager, contractGasProvider, BINARY, "");
    }

    @Deprecated
    public static RemoteCall<WeaponFactory> deploy(Web3j web3j, TransactionManager transactionManager, BigInteger gasPrice, BigInteger gasLimit) {
        return deployRemoteCall(WeaponFactory.class, web3j, transactionManager, gasPrice, gasLimit, BINARY, "");
    }

    public static class NewWeaponEventResponse {
        public Log log;

        public BigInteger weaponId;

        public String name;

        public BigInteger wepType;
    }

    public static class TransferEventResponse {
        public Log log;

        public String _from;

        public String _to;

        public BigInteger _tokenId;
    }

    public static class ApprovalEventResponse {
        public Log log;

        public String _owner;

        public String _approved;

        public BigInteger _tokenId;
    }
}
